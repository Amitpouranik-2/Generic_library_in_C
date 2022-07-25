#ifndef __MY_STACK__H
#define __MY_STACK__H 123
#include<my_common.h>
#include<my_sll.h>
typedef struct __$_my__stack
{
Singlylinkedlist *singlylinkedlist;
}Stack;

Stack * createStack(bool *success);
void pushonStack(Stack *stack ,void *ptr, bool *success);
void *popfromStack(Stack *stack , bool *success);
int getsizeofStack(Stack *stack);
void  *elementattopofStack(Stack *stack , bool *success);
bool isStackempty(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif
