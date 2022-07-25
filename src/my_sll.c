#ifndef __MY_SLL__C
#define __MY_SLL__C 123
#include<stdlib.h>
#include<my_sll.h>
Singlylinkedlist *createSinglylinkedlist(bool *success)
{
if(success) *success=false;
Singlylinkedlist *singlylinkedlist;
singlylinkedlist =(Singlylinkedlist*)malloc(sizeof(Singlylinkedlist));
if(singlylinkedlist == NULL) return NULL;
singlylinkedlist->start= NULL;
singlylinkedlist->end =NULL;
singlylinkedlist->size =0;

if(success) *success = true;
return singlylinkedlist ;
}
void destroySinglylinkedlist(Singlylinkedlist *singlylinkedlist)
{
if(singlylinkedlist== NULL)return;
clearSinglylinkedlist(singlylinkedlist);
free(singlylinkedlist);
}
int getsizeofSinglylinkedlist(Singlylinkedlist *singlylinkedlist)
{
if(singlylinkedlist== NULL)return 0;
return singlylinkedlist->size;
}
void clearSinglylinkedlist(Singlylinkedlist *singlylinkedlist)
{
SinglylinkedlistNode *node;
if(singlylinkedlist==NULL) return;
node = singlylinkedlist->start;
while(singlylinkedlist->start != NULL)
{
node = singlylinkedlist->start;
singlylinkedlist->start = singlylinkedlist->start->next;
free(node);
}
singlylinkedlist->size =0;
}
void addtoSinglylinkedlist(Singlylinkedlist *singlylinkedlist , void *ptr , bool *success)
{
SinglylinkedlistNode *node;
if(success) *success = false;
if(singlylinkedlist== NULL)return;
node=(SinglylinkedlistNode *)malloc(sizeof(SinglylinkedlistNode));
if(node==NULL)return ;
node->ptr=ptr;
node->next=NULL;
if(singlylinkedlist->start==NULL)
{
singlylinkedlist->start= node;
singlylinkedlist->end= node;
}
else
{
singlylinkedlist->end->next=node;
singlylinkedlist->end=node;
}
singlylinkedlist->size++;
if(success) *success =true;
}
void insertintoSinglylinkedlist(Singlylinkedlist *singlylinkedlist , int index, void *ptr , bool *success )
{
SinglylinkedlistNode *node , *p1, *p2;
int x;
if(success) *success =false ;
if(singlylinkedlist==NULL)return;
if(index<0 || index >singlylinkedlist->size) return ;
if(index==singlylinkedlist->size)
{
addtoSinglylinkedlist(singlylinkedlist,ptr,success);
return;
}
node=(SinglylinkedlistNode *)malloc(sizeof(SinglylinkedlistNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
if(index==0)
{
node->next = singlylinkedlist->start;
singlylinkedlist->start=node;
singlylinkedlist->size++;
if(success) *success = true;
return ;
}
p1=singlylinkedlist->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next =p1;
p2->next= node;
singlylinkedlist->size++;
if(success) *success = true;
}
void *removefromSinglylinkedlist(Singlylinkedlist *singlylinkedlist ,int index , bool *success)
{
void *ptr ;
SinglylinkedlistNode *p1 , *p2;
int x;
if(success) *success=false;
if(singlylinkedlist== NULL)return NULL;
if(index<0 || index>= singlylinkedlist->size)return NULL;
p1=singlylinkedlist->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr= p1->ptr;
if(singlylinkedlist->start ==p1 && singlylinkedlist->end==p1)
{
singlylinkedlist->start= NULL;
singlylinkedlist->end=NULL;
}
else if(singlylinkedlist->start == p1)
{
singlylinkedlist->start=singlylinkedlist->start->next;
}
else if(singlylinkedlist->end == p1)
{
singlylinkedlist->end= p2;
singlylinkedlist->end-> next= NULL;
}
else
{
p2->next = p1->next;
}
free(p1);
singlylinkedlist->size--;
if(success) *success = true;
return ptr;
}
void appendtoSinglylinkedlist(Singlylinkedlist *targetsinglylinkedlist,Singlylinkedlist *soursesinglylinkedlist, bool *success)
{
SinglylinkedlistNode *s,*e,*t,*node;
bool done ;
if(success) *success= false;
if(targetsinglylinkedlist== NULL)return;
if(soursesinglylinkedlist== NULL || soursesinglylinkedlist->size==0)
{
if(success) *success = true ;
return ;
}
s=NULL;
e=NULL;
done=true;
t=soursesinglylinkedlist->start ;
while(t!=NULL)
{
node=(SinglylinkedlistNode *)malloc(sizeof(SinglylinkedlistNode));
if(node==NULL)
{
node=false;
break;
}
node->ptr = t->ptr;
node->next= NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next= node;
e=node;
}
t=t->next;
}
if(done== false)
{
while(s!= NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetsinglylinkedlist->start == NULL)
{
targetsinglylinkedlist->start =s;
targetsinglylinkedlist->end= e;
targetsinglylinkedlist->size = soursesinglylinkedlist->size;
}
else
{
targetsinglylinkedlist->end->next = s;
targetsinglylinkedlist->end = e;
targetsinglylinkedlist->size = soursesinglylinkedlist->size;
}
if(success) *success =true;
}
void *getfromSinglylinkedlist(Singlylinkedlist *singlylinkedlist , int index , bool *success)
{
SinglylinkedlistNode *node;
int x;
if(success) *success = false;
if(singlylinkedlist== NULL)return NULL;
if(index<0 || index>=singlylinkedlist->size) return NULL;
x=0;
node= singlylinkedlist->start;
while(x<index)
{
node= node-> next;
x++;
}
if(success) *success = true;
return node->ptr;
}
Singlylinkedlistiterator getSinglylinkedlistiterator
(Singlylinkedlist *singlylinkedlist , bool *success)
{
Singlylinkedlistiterator singlylinkedlistiterator;
singlylinkedlistiterator.node= NULL;
if(success) *success = false;
if(singlylinkedlist ==NULL) return singlylinkedlistiterator;
if(singlylinkedlist->start ==NULL)
{
if(success) *success = true;
return singlylinkedlistiterator ;
}
if(success) *success = true;
singlylinkedlistiterator . node = singlylinkedlist ->start;
 return singlylinkedlistiterator;
}

bool hasnextinSinglylinkedlist(Singlylinkedlistiterator *singlylinkedlistiterator)
{
if(singlylinkedlistiterator == NULL) return false ;
if(singlylinkedlistiterator-> node == NULL) return false;
return true;
}
void *getnextelementfromSinglylinkedlist(Singlylinkedlistiterator *singlylinkedlistiterator , bool *success)
{
void *ptr = NULL;
if(success) *success =false;
if(singlylinkedlistiterator== NULL || singlylinkedlistiterator->node == NULL)return ptr;
 ptr= singlylinkedlistiterator->node->ptr;
singlylinkedlistiterator->node = singlylinkedlistiterator->node->next;
if(success) *success = true;
return ptr;
}
#endif
