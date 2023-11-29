#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_chopstick = philosopher_id;
    int right_chopstick = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopher_id);
        sleep(rand() % 3 + 1);

        printf("Philosopher %d is hungry\n", philosopher_id);
        sem_wait(&chopsticks[left_chopstick]);
        sem_wait(&chopsticks[right_chopstick]);

        printf("Philosopher %d is eating\n", philosopher_id);
        sleep(rand() % 3 + 1);

        sem_post(&chopsticks[left_chopstick]);
        sem_post(&chopsticks[right_chopstick]);
    }

    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        sem_init(&chopsticks[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
