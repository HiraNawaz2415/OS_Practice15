#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

#define CHAIRS 5
int waiting = 0;
sem_t customers, barbers;
pthread_mutex_t mutex;

void* barber(void* arg) {
    while (1) {
        sem_wait(&customers);
        pthread_mutex_lock(&mutex);
        waiting--;
        pthread_mutex_unlock(&mutex);
        sem_post(&barbers);
        printf("Cutting hair\n");
    }
}

void* customer(void* arg) {
    pthread_mutex_lock(&mutex);
    if (waiting < CHAIRS) {
        waiting++;
        sem_post(&customers);
        pthread_mutex_unlock(&mutex);
        sem_wait(&barbers);
        printf("Getting haircut\n");
    } else {
        pthread_mutex_unlock(&mutex);
        printf("Leaving shop\n");
    }
}
