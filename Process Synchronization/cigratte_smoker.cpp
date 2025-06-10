#include <iostream>
#include <semaphore.h>
#include <pthread.h>
using namespace std;

sem_t tobacco, paper, match;

void* agent(void* arg) {
    while (true) {
        int r = rand() % 3;
        if (r == 0) {
            sem_post(&paper);
            sem_post(&tobacco);
        } else if (r == 1) {
            sem_post(&paper);
            sem_post(&match);
        } else {
            sem_post(&match);
            sem_post(&tobacco);
        }
    }
}

void* smokerWithPaper(void* arg) {
    while (true) {
        sem_wait(&tobacco);
        sem_wait(&match);
        cout << "Smoker with paper is smoking\n";
    }
}
