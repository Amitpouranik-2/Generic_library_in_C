#ifndef _MY__ARRAY_H 
#define _MY__ARRAY_H 123

#include<my_common.h>
typedef struct __array
{
int size;
int rows;
void ***x;
}Array;

Array *createArray( int *success);
void setelementofArray(Array *array , int index , void *element,int *success);
void *getelementofArray(Array *array,  int index);
int getsizeofArray(Array *);
#endif
