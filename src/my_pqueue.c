#ifndef __MY_PQUEUE_C
#define __MY_PQUEUE_C  123
#include<stdio.h>
#include<stdlib.h>
#include<my_heap.h>
#include<my_pqueue.h>

PQueue *createPQueue(int (*predicate)(void*, void*), bool *success)
{
PQueue *pqueue;
Heap *heap;
heap = createHeap(predicate ,success);
if(*success == false) return NULL;
pqueue = (PQueue*)malloc(sizeof(PQueue));
if(pqueue == NULL)
{
if(success) *success = false;
 return NULL;
}
pqueue->heap= heap ;
if(success) *success = true;
return pqueue;
}
void AddtoPQueue(PQueue *pqueue , void *ptr , bool *success)
{
if(success) *success = false;
if(pqueue == NULL || pqueue->heap == NULL) return;
addtoHeap(pqueue->heap , ptr , success);
if(success) *success=true;
}
void * RemovefromPQueue(PQueue *pqueue , bool *success)
{
void *ptr;
if(success) *success = false;
if(isPQueueEmpty(pqueue)) return NULL;
ptr = removefromHeap(pqueue->heap , success);
if(success) *success =true;
return ptr;
}
int getsizeofPQueue(PQueue *pqueue)
{
if(pqueue == NULL || pqueue->heap ==NULL) return 0;
return getsizeofHeap(pqueue->heap);
}
void *ElementAtFrontOfPQueue(PQueue *pqueue , bool *success)
{
void *ptr;
if(success) *success = false;
if(isPQueueEmpty(pqueue)) return NULL;
ptr = elementAtOfHeap(pqueue->heap , success);
if(success) *success  = true;
return ptr;
}

bool isPQueueEmpty(PQueue *pqueue)
{
if(pqueue == NULL) return true;
if(pqueue->heap == NULL) return true;
if(getsizeofHeap(pqueue->heap)== 0) return true;
return false;
}
void clearPQueue(PQueue *pqueue)
{
int succ;
if(pqueue ==NULL) return;
if(pqueue->heap == NULL) return;
while(getsizeofHeap(pqueue->heap)>0)
{
removefromHeap(pqueue->heap , &succ);
}
}

void destroyPQueue(PQueue *pqueue)
{
if(pqueue== NULL) return;
if(pqueue->heap ==NULL) return;
free(pqueue);
}
#endif