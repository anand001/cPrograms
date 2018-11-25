/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int
main ()
{
  printf ("Hello World\n");

  int rows = 3, columns = 3;
  int i, j, count = 0;
/**************** Method - 1 ***************************************/
  int **arr1 = (int **) malloc (rows * columns * sizeof (int));

  //Array Access:
  for (i = 0; i < rows; i++)
    for (j = 0; j < columns; j++)
      *(arr1 + i * columns + j) = ++count;

  for (i = 0; i < rows; i++)
    for (j = 0; j < columns; j++)
      printf ("%d", *(arr1 + i * columns + j));

  // free is required so as to make other parts work accordingly
//  for (i = 0; i < rows*columns; i++)
//    free (arr1[i]);

/************ Method - 3 *******************************************/
  int **arr3 = (int **) malloc (sizeof (int *) * rows);

  for (i = 0; i < rows; i++)
    arr3[i] = (int *) malloc (sizeof (int) * columns);

//Array Access:
  for (i = 0; i < rows; i++)
    for (j = 0; j < columns; j++)
      arr3[i][j] = ++count;

  for (i = 0; i < rows; i++)
    for (j = 0; j < columns; j++)
      printf ("%d", arr3[i][j]);


  for (int i = 0; i < columns; i++)
    free (arr3[i]);
  free (arr3);
/*******************************************************************/
  return 0;
}
