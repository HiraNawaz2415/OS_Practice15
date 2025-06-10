#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    int item = 1;
    while (1) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item++;
        in = (in + 1) % SIZE;
        printf("Produced\n");
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        out = (out + 1) % SIZE;
        printf("Consumed\n");
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
