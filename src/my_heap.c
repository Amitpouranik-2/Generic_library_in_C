#ifndef _MY_HEAP_C
#define _MY_HEAP_C 123
#include<stdio.h>
#include<stdlib.h>
#include<my_heap.h>
#include<my_array.h>

Heap *createHeap(int (*comparator)(void* , void*) , int *success)
{
Heap *heap = NULL;
int succ;
if(success) *success = false;
if(comparator== NULL)  return NULL;
heap = (Heap*)malloc(sizeof(Heap));
if(heap==NULL) return heap;
heap->array = createArray(&succ);
if(!succ)
{
free(heap);
return NULL;
}
heap->size =0;
heap->comparator = comparator;
if(success) *success = true;
return heap;
}


void addtoHeap( Heap *heap , void *element, int *success)
{
int ri,ci,weight, succ;
void *ciValue , *riValue;
if(success) *success = false;
if(heap==NULL) return ;
setelementofArray(heap->array , heap->size , element , &succ);
if(!succ) return;
heap->size++;
ci = heap->size -1;
while(ci>0)
{
ri= (ci-1)/2;
ciValue = getelementofArray(heap->array , ci);
riValue = getelementofArray(heap->array , ri);
weight = heap->comparator(ciValue , riValue);
if(weight<0)
{
setelementofArray(heap->array,ci,riValue,&succ);
setelementofArray(heap->array,ri,ciValue,&succ);
ci=ri;
}
else
{
break;
}
}
if(success) *success = true;
}

void *removefromHeap(Heap *heap , int *success)
{
void *element , *lastelement , *swiValue , *riValue;
int ri , swi, lci, rci, succ , upperbound ;
if(success) *success = false;
if(heap == NULL) return NULL;
if(heap->size== 0) return NULL;
element = getelementofArray(heap->array ,0);
lastelement = getelementofArray(heap->array , heap->size-1);
setelementofArray(heap->array , 0 , lastelement , &succ);
heap->size--;
upperbound = heap->size-1;
ri=0;
while(ri<upperbound)
{
lci = (ri*2)+1;
if(lci>upperbound) break;
rci = lci+1;
if(rci >upperbound)
{
swi = lci;
}
else
{
if(heap->comparator(getelementofArray(heap->array,lci), getelementofArray(heap->array, rci)) <0)
{
swi= lci;
}
else
{
swi = rci;
}
}
riValue = getelementofArray(heap->array , ri);
swiValue = getelementofArray(heap->array , swi);
if(heap->comparator(swiValue , riValue) < 0)
{
setelementofArray(heap->array , swi , riValue , &succ);
setelementofArray(heap->array , ri , swiValue , &succ);
ri = swi;
}
else
{
break;
}
}
if(success) *success = true;
return element;
}

void *elementAtOfHeap(Heap *heap , int *success)
{
void *eat;
if(success) *success = false;
if(heap== NULL) return NULL;
if(heap->size==0) return NULL;
if(success) *success = true;
return getelementofArray(heap->array , 0);
}

int getsizeofHeap(Heap *heap)
{
if(heap== NULL) return 0;
return heap->size;
}

void *getElementfromHeap(Heap *heap , int index  , int *success)
{
void *element = NULL;
if(success) *success = false;
if(heap == NULL) return element;
if(index < 0 || index >= heap->size) return element;
element = getelementofArray(heap->array , index);
if(success) *success = true;
return element;
}

void updateElementinHeap(Heap *heap , int index , void *element , int *success)
{
int succ, ri, ci, swi, upperbound , godown, lci ,rci , weight ;
void *swiValue , *riValue , *ciValue ;
if(success) *success = false;
if(heap == NULL) return ;
if(index < 0 || index >= heap->size) return ;
setelementofArray(heap->array , index , element , &succ);
if(index== 0)
{
godown = true;
}
else if(index == heap->size-1)
{
godown = false;
}
else
{
ci =index;
ri =(ci-1)/2;
ciValue = getelementofArray(heap->array , ci);
riValue = getelementofArray(heap->array , ri);
weight = heap->comparator(ciValue , riValue);
if(weight <0) godown = false;
else godown = true;
}
if(godown)
{
upperbound = heap->size-1;
ri =index;
while(ri<upperbound)
{
lci = (ri*2)+1;
if(lci >upperbound) break;
rci = lci +1;
if(rci > upperbound)
{
swi = lci;
}
else
{
if(heap->comparator(getelementofArray(heap->array , lci), getelementofArray(heap->array , rci))<0)
{
swi = lci;
}
else
{
swi = rci;
}
}
riValue = getelementofArray(heap->array , ri);
swiValue = getelementofArray(heap->array , swi);
if(heap->comparator(swiValue, riValue)<0)
{
setelementofArray(heap->array ,swi , riValue, &succ);
setelementofArray(heap->array , ri , swiValue , &succ);
ri =swi;
}
else
{
break;
}
}
}
else
{
ci =index;
while(ci>0)
{
ri = (ci-1)/2;
ciValue =  getelementofArray(heap->array , ci);
riValue = getelementofArray(heap->array , ri);
weight = heap->comparator(riValue , ciValue);
if(weight<0)
{
setelementofArray(heap->array , ci , riValue , &succ);
setelementofArray(heap->array , ri , ciValue , &succ);
ci = ri;
}
else
{
break;
}
}
}
if(success) *success = true;
}
#endif



