#ifndef __MY_HEAP_H 
#define __MY_HEAP_H  123
#include<my_common.h>
#include<my_array.h>
typedef struct __heap
{
Array *array;
int (*comparator)(void *, void * );
int size;
} Heap;

Heap *createHeap(int (*comparator)(void *, void * ) , int *success);
void addtoHeap( Heap *heap , void *element, int *success);
void *removefromHeap( Heap *heap , int *success);
void *elementAtOfHeap(Heap *heap , int *success);
int getsizeofHeap(Heap *heap);
void destroyHeap(Heap *heap);
void *getElementfromHeap(Heap *heap , int index  , int *success);
void updateElementinHeap(Heap *heap , int index , void *element , int *success);
#endif
