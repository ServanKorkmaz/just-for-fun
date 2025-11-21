#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_THREADS 50


sem_t semaphore;

void *rate_limited_task(void *arg) {
int thread_id = *(int *)arg;
printf("Thread %d started\n", thread_id);

// Simulate a time-consuming task
sleep(1);
printf("Thread %d finished task\n", thread_id);
return NULL;
}


int main() {
pthread_t threads[MAX_THREADS];
int thread_ids[MAX_THREADS];
int i;
sem_init(&semaphore, 0, X);



// Create threads
for (i = 0; i < MAX_THREADS; i++) {
thread_ids[i] = i;
pthread_create(&threads[i], NULL, rate_limited_task, &thread_ids[i]);
}

// Join threads
for (i = 0; i < MAX_THREADS; i++) {
pthread_join(threads[i], NULL);
}
sem_destroy(&semaphore);
return 0;
}