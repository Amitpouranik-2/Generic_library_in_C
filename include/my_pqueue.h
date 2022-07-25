#ifndef __MY_PQUEUE_H
#define __MY_PQUEUE_H 123
#include<my_common.h>
#include<my_heap.h>
typedef   struct __$_my_pqueue
{
Heap *heap;
}PQueue;

PQueue *createPQueue(int (*predicate)(void*, void*), bool *success);
void AddtoPQueue(PQueue *pqueue , void *ptr , bool *success);
void *RemovefromPQueue(PQueue *pqueue , bool *success);
int getsizeofPQueue(PQueue *pqueue);
void *ElementAtFrontOfPQueue(PQueue *pqueue , bool *success);
bool isPQueueEmpty(PQueue *pqueue);
void clearPQueue(PQueue *pqueue);
void destroyPQueue(PQueue *pqueue);
#endif