#ifndef __MY_ARRAY_H
#define __MY_ARRAY_H 123
#include<stdio.h>
#include<stdlib.h>
#include<my_array.h>
Array *createArray( int *success )
{
Array *array;
if(success) *success = false;
array = (Array*)malloc(sizeof(Array));
if(array== NULL) return array;
array->rows=0;
array->size= 0;
array->x =NULL;
if(success) *success = true;
return array;
}

void setelementofArray(Array *array , int index , void *element,int *success)
{
int rowindex , columnindex;
void ***myp;
int sp,ep, i;
if(success) *success = false;
rowindex = index/10;
columnindex = index%10;
if(rowindex >= array->rows)
{
if(array->x!=NULL)
{
myp = (void***)calloc(rowindex+1, sizeof(void**));
if(myp ==NULL) return ;
sp=0;
ep=array->rows-1;
for(i=sp; i<=ep;  i++)
{
myp[i] = array->x[i];
}
free(array->x);
array->x = myp ;
array->rows = rowindex+1;
}
else
{
array->x = (void***)calloc(rowindex+1, sizeof(void**));
if(array->x == NULL) return;
array->rows = rowindex +1;
}
}
if(array->x[rowindex] == NULL)
{
array->x[rowindex] = (void**)calloc(10,sizeof(void*));
if(array->x[rowindex]== NULL) return ;
}
array->x[rowindex][columnindex] = element;
if(index >= array->size) array->size= index+1;
if(success) *success = true;
} 

void *getelementofArray(Array *array, int index)
{
int rowindex , columnindex ;
if(array->x ==NULL) return NULL;
rowindex = index/10;
if(rowindex >= array->rows ) return NULL;
if(array->x[rowindex]== NULL) return NULL;
columnindex = index%10;
return array->x[rowindex][columnindex];
}

int getsizeofArray(Array *array)
{
return array->size;
}
#endif