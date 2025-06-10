#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t wrt;
pthread_mutex_t mutex;
int readCount = 0;

void* reader(void* arg) {
    pthread_mutex_lock(&mutex);
    readCount++;
    if (readCount == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    cout << "Reading\n";

    pthread_mutex_lock(&mutex);
    readCount--;
    if (readCount == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void* writer(void* arg) {
    sem_wait(&wrt);
    cout << "Writing\n";
    sem_post(&wrt);
}
