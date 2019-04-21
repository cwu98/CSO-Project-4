#include <stdio.h>
#include <stdlib.h>
#include "given/functions2.h"

// IMPLEMENT FUNCTIONS IN THIS FILE
/* Author: Cary Wu
 * Description: implementations of two functions based on disassembled versions of the functions2.o object file
 */


long fun1 ( data a[], int size ){
  int x ;
  long val = 0;
  for(x=0;x<size;x++){
    val = val+a[x].i;
}
  return val;
}

char* fun2 ( data a[], int size ){
  printf("start of fun2\n");
  char *foo = fun2(a,size+1);
  *(foo+size)='\0'; //end of string
  int j=0;
  for(j=0;j<size;j++){
    *(foo+j)=a[j].c;
  }
  return foo;

}
