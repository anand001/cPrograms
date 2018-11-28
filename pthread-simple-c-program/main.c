/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>

void *tprint (void *args);
void *sum (void *args);

// to give multiple input arguments to thread2
struct inputs
{
    int i1;
    int i2;
};

// task to be executed in thread1
void *tprint (void *args)
{
  printf ("Inside Thread1: print, with no arguments\n");
}

// task to be executed in thread2
void *tsum (void *args)
{
  struct inputs *pval = (struct inputs *)args;
  int result = pval->i1 + pval->i2;;
  printf ("Inside Thread2: sum with 2 arguments, result is %d\n", result);
}

main ()
{
  printf ("Hello World\n");

  // using pthread_t we indicate that thread exist in our program
  pthread_t thread1_id, thread2_id;
  int a = 2;
  struct inputs val;
  val.i1 = 5;
  val.i2 = 6;

  // create the thread
  /*
     arg1 --> pointer to thread id; After creating the thread, its id will be stored at the address of threadId
     arg2 --> if NULL, that indicates use the default attributes to create a thread.
     arg3 --> Thread is created executing this routine with input arguments as arg4
     int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
   */
  pthread_create (&thread1_id, NULL, tprint, (void *) &a);
  pthread_create (&thread2_id, NULL, tsum, (void *) &val);

  // wait for thread to exit before continue operation
  /* 
     suspends execution of the calling thread until the target thread terminates
     arg1 -->  thread id for which it shall wait to terminate
     arg2 --> if not NULL, storest the argument that is passed to thread_exit call
     multiple simultaneous calls to pthread_join() specifying the same target thread are undefined
     int pthread_join(pthread_t thread, void **value_ptr);
   */
   pthread_join (thread2_id, NULL);
   pthread_join (thread1_id, NULL);
}
