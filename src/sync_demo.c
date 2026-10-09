#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "sync_demo.h"

static pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

static void *thread_a(void *arg)
{
    (void)arg;
    printf("[Thread A] Attempting to acquire Lock 1...\n");
    pthread_mutex_lock(&lock1);
    printf("[Thread A] Acquired Lock 1. Simulating work...\n");
    sleep(1);
    printf("[Thread A] Attempting to acquire Lock 2...\n");
    pthread_mutex_lock(&lock2);
    printf("[Thread A] Acquired Lock 2!\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

static void *thread_b(void *arg)
{
    (void)arg;
    printf("[Thread B] Attempting to acquire Lock 2...\n");
    pthread_mutex_lock(&lock2);
    printf("[Thread B] Acquired Lock 2. Simulating work...\n");
    sleep(1);
    printf("[Thread B] Attempting to acquire Lock 1...\n");
    pthread_mutex_lock(&lock1);
    printf("[Thread B] Acquired Lock 1!\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

void execute_deadlock(void)
{
    pthread_t t1, t2;

    printf("Starting Deadlock Demonstration...\n");
    printf("Press Ctrl+C to kill the shell when it hangs.\n");

    pthread_create(&t1, NULL, thread_a, NULL);
    pthread_create(&t2, NULL, thread_b, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
