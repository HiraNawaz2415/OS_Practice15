#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define N 5

sem_t forks[N];
sem_t waiter;

void* philosopher(void* num) {
    int i = *(int*)num;
    sem_wait(&waiter);
    sem_wait(&forks[i]);
    sem_wait(&forks[(i+1)%N]);
    printf("Philosopher %d is eating\n", i);
    sem_post(&forks[i]);
    sem_post(&forks[(i+1)%N]);
    sem_post(&waiter);
}
