#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5 // number of philosophers

sem_t chopsticks[N];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;
    while (1) {
        printf("Philosopher %d is thinking\n", id);
        sem_wait(&chopsticks[left]);
        sem_wait(&chopsticks[right]);
        printf("Philosopher %d is eating\n", id);
        sem_post(&chopsticks[right]);
        sem_post(&chopsticks[left]);
    }
}

int main() {
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
