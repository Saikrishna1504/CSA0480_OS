#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2
#define NUM_ITEMS 10

sem_t empty, full;
pthread_mutex_t buffer_lock;

int buffer[BUFFER_SIZE];
int buffer_index = 0;

void *producer(void *arg) {
    int producer_id = *(int *)arg;

    for (int i = 0; i < NUM_ITEMS; ++i) {
        int item = rand() % 100; 
        sem_wait(&empty);
        pthread_mutex_lock(&buffer_lock);

        buffer[buffer_index] = item;
        printf("Producer %d produced item %d\n", producer_id, item);
        buffer_index++;

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&full);
        sleep(1); // Simulate production time
    }

    return NULL;
}

void *consumer(void *arg) {
    int consumer_id = *(int *)arg;

    for (int i = 0; i < NUM_ITEMS; ++i) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_lock);

        int item = buffer[--buffer_index];
        printf("Consumer %d consumed item %d\n", consumer_id, item);

        pthread_mutex_unlock(&buffer_lock);
        sem_post(&empty);
        sleep(1); // Simulate consumption time
    }

    return NULL;
}

int main() {
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buffer_lock, NULL);

    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        producer_ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        consumer_ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&buffer_lock);

    return 0;
}
