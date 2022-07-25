#ifndef __MY_STACK__C
#define __MY_STACK__C 123
#include<stdio.h>
#include<stdlib.h>
#include<my_stack.h>
#include<my_sll.h>
Stack * createStack(bool *success)
{
Stack *stack;
Singlylinkedlist *singlylinkedlist;
singlylinkedlist = createSinglylinkedlist(success);
if(*success == false) return NULL;
stack = (Stack *)malloc (sizeof(Stack));
if(stack==NULL)
{
destroySinglylinkedlist(singlylinkedlist);
if(success) *success= false;
return NULL;
}
stack->singlylinkedlist=singlylinkedlist;
if(success)*success = true;
return stack;
}
void pushonStack(Stack *stack ,void *ptr, bool *success)
{
if(success) *success = false;
if(stack== NULL || stack->singlylinkedlist== NULL) return ;
insertintoSinglylinkedlist(stack->singlylinkedlist, 0,ptr ,success);
} 
void *popfromStack(Stack *stack , bool *success)
{
void *ptr;
if(success) *success =false;
if(isStackempty(stack)) return NULL;
ptr= removefromSinglylinkedlist(stack->singlylinkedlist,0,success);
if(success) *success = true;
return ptr;
}
int getsizeofStack(Stack *stack)
{
if(stack==NULL || stack->singlylinkedlist== NULL)return 0;
return getsizeofSinglylinkedlist(stack->singlylinkedlist);
}
void * elementattopofStack(Stack *stack , bool *success)
{
void *ptr;
if(success) *success= false;
if(isStackempty(stack)) return NULL;
ptr= getfromSinglylinkedlist(stack->singlylinkedlist,0,success);
if(success)*success = true;
return ptr;
}

bool isStackempty(Stack *stack)
{
if(stack==NULL) return true;
if(stack->singlylinkedlist == NULL) return true ;
if(getsizeofSinglylinkedlist(stack->singlylinkedlist)== 0) return true;
return false;
}
void clearStack(Stack *stack)
{
if(stack==NULL) return ;
if(stack->singlylinkedlist == NULL)return ;
clearSinglylinkedlist(stack->singlylinkedlist);
}
void destroyStack(Stack *stack)
{
if(stack== NULL) return ;
if(stack->singlylinkedlist == NULL)return;
destroySinglylinkedlist(stack->singlylinkedlist);
free(stack);
}
#endif
