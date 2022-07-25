#ifndef  __MY_SLL__H
#define __MY_SLL__H 123
#include <my_common.h>
    typedef struct __$_my_sll_node
{
    void *ptr;
    struct __$_my_sll_node *next;
} SinglylinkedlistNode;
typedef struct __$_my_sll
{
    struct __$_my_sll_node *start;
    struct __$_my_sll_node *end;
    int size;
}
Singlylinkedlist;

typedef struct __$_my_sll_iterator
{
SinglylinkedlistNode *node;
}Singlylinkedlistiterator;
Singlylinkedlist *createSinglylinkedlist(bool *success);
void destroySinglylinkedlist(Singlylinkedlist *singlylinkedlist);
int getsizeofSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
void addtoSinglylinkedlist(Singlylinkedlist *singlylinkedlist, void *ptr, bool *success);
void insertintoSinglylinkedlist(Singlylinkedlist *singlylinkedlist, int index, void *ptr, bool *success);
void *removefromSinglylinkedlist(Singlylinkedlist *singlylinkedlist, int index, bool *success);
void clearSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
void appendtoSinglylinkedlist(Singlylinkedlist *targetSinglylinkedlist, Singlylinkedlist *sourceSinglylinkedlist, bool *success);
void *getfromSinglylinkedlist(Singlylinkedlist *singlylinkedlist, int index, bool *success);

Singlylinkedlistiterator getSinglylinkedlistiterator(Singlylinkedlist *singlylinkedlist , bool *success);
bool hasnextinSinglylinkedlist(Singlylinkedlistiterator *singlylinkedlistiterator);

void *getnextelementfromSinglylinkedlist(Singlylinkedlistiterator *singlylinkedlistiterator, bool *success);



#endif

