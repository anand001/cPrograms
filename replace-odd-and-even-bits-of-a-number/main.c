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
  printf ("Hello World");

  unsigned long int ev = 0xAAAAAAAAAAAAAAAA;
  unsigned long int od = 0x5555555555555555;
  unsigned int num, temp1, temp2;

  scanf ("%d", &num);
  temp1 = num;

  // binary representation of number in reverse order
  while (temp1 != 0)
    {
      temp2 = temp1 % 2;
      printf ("%d", temp2);
      temp1 = temp1 / 2;
    }

  // replace even and odd digits with each other
  num = (num & ev) >> 1 | (num & od) << 1;
  printf ("\n%d\n", num);
  return 0;
}
