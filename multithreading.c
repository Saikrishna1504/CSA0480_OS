#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread %d is running\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; ++i) {
        pthread_create(&threads[i], NULL, thread_function, &i);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished\n");

    return 0;
}
