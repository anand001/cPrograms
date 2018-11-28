/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int var = 5;
sem_t mutex;
void *commonCode(void *);
void *commonCode(void *x)
{
    printf("inside thread\n");
    int a=2, b=3,c,d;

    //locks the semaphore, decrement the counter, int sem_wait(sem_t *sem);
    sem_wait(&mutex);   
    c = a+b;
    d = a+b+c;
    printf("%d\n",d);
    //unlocks the semaphore, increase the semaphore counter, int sem_post(sem_t *sem);
    sem_post(&mutex);
}

int main()
{
    printf("Hello World\n");
    pthread_t thread1, thread2;
    
    /*
    int sem_init(sem_t *sem, int pshared, unsigned int value); , link with pthread_t, needs semaphore.h
     arg3 --> Specifies the value to assign to the newly initialized semaphore.
     arg2 --> If 0, specify that semaphore is shared b/w threads of a process, and shall be stored at common mem location.
              If non-zero, specify that semaphore is shared between the processes.
     arg1 --> specifies the semaphore to be initialized.
     Initializing a semaphore that has already been initialized results in undefined behavior.
     sem_init returns 0 if it succeeds and -1 if anything goes wrong.
    */
    sem_init(&mutex, 0, 1); 
    pthread_create (&thread1, NULL, (void *) &commonCode, (void *)&var);
    pthread_create (&thread2, NULL, (void *) &commonCode, (void *)&var);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    /*destroy the unnamed semaphore,
    Only a semaphore that was created using sem_init() may be destroyed using sem_destroy()
        sem_destroy(sem_t *sem);
    */
    sem_destroy(&mutex);
    
    return 0;
}
