#include <stdio.h>
#include <pthread.h>

__thread int tls_counter = 0;

void* thread_func(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        tls_counter++; 
    }
    printf("Thread %ld: tls_counter = %d\n", pthread_self(), tls_counter);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}