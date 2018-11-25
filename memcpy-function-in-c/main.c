/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void a_memcpy (void *dest, const void *src, int size);

// loop implemented inside this function depends upon the size passed to the function
void a_memcpy (void *dest, const void *src, int size)
{
/*********************************************************************/
  /* For character */
  char *cdest = (char *) dest;
  char *csrc = (char *) src;

  for (int i = 0; i < size; i++)
    {
      cdest[i] = csrc[i];
      printf ("%d\t", csrc[i]);
    }
  printf ("\n");
/**********************************************************************/
  /* for integer */
  int *idest = (int *) dest;
  int *isrc = (int *) src;

  for (int i = 0; i < (size / sizeof (int)); i++)
    {
      idest[i] = isrc[i];
      //cdest++;csrc++;size--;
      printf ("%d\t", idest[i]);
    }
  printf ("\n");
/**********************************************************************/

}

int main ()
{
  printf ("Hello World\n");

  const int numArr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int size = sizeof (numArr1) / sizeof (numArr1[0]);
  int numArr2[size];

  // sizeof numArr1 --> 9*4 = 36
  // size of numArr[0] --> 4
  printf ("%d\t%d\t%d\n", sizeof (numArr1), sizeof (numArr1[0]), size);

  // make sure to pass the correct size value 
  a_memcpy (numArr2, numArr1, sizeof (numArr1));

  for (int i = 0; i < size; i++)
    printf ("%d\t", numArr2[i]);
  return 0;

}
