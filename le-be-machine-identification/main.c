/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    printf("Hello World\n");
    
    unsigned int a = 0x12345678;
    
    char *c = (char *)&a;
    
    if(*c == 0x78)
        printf("LE\t%x\n",*c);
    else
        printf("BE\t%x\n",*c);

    return 0;
}
