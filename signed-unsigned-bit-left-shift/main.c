/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int
main ()
{
  printf ("Hello World\n");

  int a1 = -6;			// 0101 -> 1011
  int a2 = 6;
  printf ("%d\n", a1);
  printf ("%d\n", a2);
  int res1, res2;

  // left shift divides the number in half whether its a +ve or -ve number
  // +-8 --> +-4; +-6 --> +-3; and so on ...
  // +7 -> +3; -7 -> -4 ;; +5 -> +2; -5 -> -3
  res1 = a1 >> 1;
  res2 = a2 >> 1;
  printf ("%d\n", res1);
  printf ("%d\n", res2);

  return 0;
}
