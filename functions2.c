#include <stdio.h>
#include <stdlib.h>
#include "given/functions2.h"

// IMPLEMENT FUNCTIONS IN THIS FILE
/* Author: Cary Wu
 * Description: implementations of two functions based on disassembled versions of the functions2.o object file
 */


/*
 *fun1 sums up all .i values in an array of 'data' type structures and returns the sum 
*/
long fun1 ( data a[], int size ){
  int x ;
  long val = 0;
  for(x=0;x<size;x++){
    val = val+a[x].i;
}
  return val;
}

/*
 * fun2 returns a string that concatenates chars stored in .c field in an array of 'data' type structures
 */
char* fun2 ( data a[], int size ){
 
  char *foo = malloc((size+1)*sizeof(char));
  *(foo+size)='\0'; //end of string
  int j=0;
  for(j=0;j<size;j++){
    *(foo+j)=a[j].c;
  }
  return foo;

}
