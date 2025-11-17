#include <stdio.h>
#include <pthread.h>

int balance = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {

    pthread_mutex_lock(&lock);
    balance++;
    pthread_mutex_unlock(&lock);

    return NULL;
    
}

int main(int argc, char *argv[]) {
    pthread_t p;
    pthread_create(&p, NULL, worker, NULL);

    pthread_mutex_lock(&lock);
    balance++;
    pthread_mutex_unlock(&lock);

    pthread_join(p, NULL);
    printf("balance: &d/n", balance);   // should print: balance: 2
    return 0;
}

