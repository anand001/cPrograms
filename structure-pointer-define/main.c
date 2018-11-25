/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct sample
{
  int a;
  int b;
} *stp;

int
main ()
{
  printf ("Hello World\n");

  struct sample st;
  st.a = 5;
  st.b = 6;

  printf ("%d\t%d\n", st.a, st.b);

// without defining structure pointer here, it will throw a segmentation pointer as global variables are initialized to zero, in that case it will be a null pointer
//struct sample *stp = malloc(sizeof(struct sample *));     // dynamic memory allocation, change will not be reflected to st
  struct sample *stp = &st;	// static memory allocation, reflect any change in stp to st also
//struct sample *stp;               // garbage value to pointer
  stp->a = 8;
  stp->b = 9;

  printf ("%d\t%d\n", stp->a, stp->b);
  printf ("%d\t%d\n", st.a, st.b);

  return 0;
}
