# DOCUMENTATION

## Overview
here you get to know about `library` of GENERIC data structures, which is built in `c` programming language.


## Generic Library inspired by `STL` in `C++`
  
* Language Used :- `C` Programming.
* Key Features :- It Includes Data Structures like Singly Linked List , Doubly Linked list , Stack , Queue , Priority_Queue
                  AVL Tree , Heap , Arrays.

* It is Useful for a User who are Working on `C` Projects.
* In `C++` , with the Help of STL we Can use all the Data Structures Directly 
 But  in `C` we need to write code from Scratch.
* but Including This Generic Library we don't need to Write Code from scratch
*for example - if we want to use stack then simply include `<stack.h>` header file like `stdio.h`   




## Why The Generic Data Structure In C ?
we have `STL in C++`, `Collection classes in Java` but when we talk about `C` so there is no such facilites to handle some huge data. 


* [Generic Singly Linked List](#generic-singly-linked-list)  
   * [Singly Linked List Iterator](#description-of-iterator-functions-of-singly-linked-list)
   * [Use of Singly Linked List](#use-of-singly-linked-list-)
* [Generic Doubly Linked List](#generic-doubly-linked-list)  
   * [Doubly Linked List Iterator](#description-of-iterator-functions-of-doubly-linked-list-)
   * [Use of Doubly Linked List](#use-of-doubly-linked-list-)
* [Generic Stack](#generic-stack)
   * [Use of Stack](#use-of-stack-)
* [Generic Queue](#generic-queue)
   * [Use of Queue](#use-of-queue-)
* [Generic AVL Tree](#generic-avl-tree)  
   * [AVL Tree Iterator](#description-of-iterator-functions-of-avl-tree)
   * [Use of AVL Tree](#use-of-avl-tree-)
* [Generic Heap](#generic-heap)
   * [Use of Heap](#use-of-heap-)
* [Generic Array](#generic-Array)
   * [Use of Array](#use-of-Array-) 
    
## Generic Singly Linked List  
***
### Description of Main functions :

* To `create` Singlylinkedlist
   ```c
   Singlylinkedlist * createSinglylinkedlist(bool *success); 
   ```
   `bool success;`  
    `Singlylinkedlist *list;`  
    `list=createSinglylinkedlist(&success);`  
    if(`success==true`) list is created.  
    if(`success==false`) list is not created.  


* To `add` element in Singly Linked List
  ```c
  void addtoSinglylinkedlist(Singlylinkedlist *singlylinkedlist,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;`  
  `addtoSinglylinkedlist(list,(void *)&i,&success);`  
   if(`success==true`) element is added.  
   if(`success==false`) element is not added.  
    
* To `insert` element in Singly Linked List
   ```c
   void insertintoSinglylinkedlist(Singlylinkedlist *singlylinkedlist,int index,void *ptr,bool *success);
   ```
  `bool success;`  
  `int i=100;`  
  `int index;` (position to insert element in list)  
  `insertintoSinglylinkedlist(list,index,(void *)&i,&success);`  
   if(`success==true`) element is inserted.  
   if(`success==false`) element is not   inserted.  
   
* To `remove` element from Singly Linked List
  ```c
  void * removefromSinglylinkedlist(Singlylinkedlist *singlylinkedlist,int index,bool *success);
  ```
  function will return removed element's address.  
  `bool success;`  
  `void * ptr;`  
  `int index;` (position to remove element in list)  
  `ptr=removefromSinglylinkedlist(list,index,&success);`  
  if(`success==true`) element is removed.  
  if(`success==false`) element is not removed.  

* To `get size` of Singly Linked List
  ```c
  int getsizeofSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  `int size;`  
  `size=getsizeofSinglylinkedlist(list);`  
* To `get an element` from Singly Linked List  
  ```c
  void * getfromSinglylinkedlist(Singlylinkedlist *singlylinkedlist,int index,bool *success);
  ```
  `bool success;`  
  `void * ptr;`  
  `int index;`  
  `ptr=getfromSinglylinkedlist(list,index,&success);`  
  if(`success==true`) element is received in ptr.  
  if(`success==false`) element is not received int ptr.  

* To `merge one list into another list` of Singly Linked List  
  ```c
  void appendtoSinglylinkedlist(Singlylinkedlist *targetSinglylinkedlist,Singlylinkedlist * sourceSinglylinkedlist,bool *success);
  ```
  we have `list_1` and `list_2` of Singlylinkedlist.  
  for merging `list_1` into `list_2`.  
  `bool success;`   
  `appendtoSinglylinkedlist(list_1,list_2,&success);`  
  if(`success==true`) lists are merged.  
  if(`success==false`) lists are not merged.  

* To `clear` the Singly Linked List  
  ```c
  void clearSinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  use to free (remove) nodes of list (size of list is zero).  
  `clearSinglylinkedlist(list);`  
* To `delete/destroy` the Singly Linked List    
  ```c
  void destroySinglylinkedlist(Singlylinkedlist *singlylinkedlist);
  ```
  use to delete the list.  
  `destroySinglylinkedlist(list);`  
  ***  
### Description of Iterator functions of Singly Linked List:  

* To `create iterator` of Singly Linked List
  ```c
  Singlylinkedlistiterator getSinglylinkedlistiterator(Singlylinkedlist *singlylinkedlist,bool *success);
  ```
  `Singlylinkedlistiterator it;`      
  `bool success;`  
  `it=getSinglylinkedlistiterator(list,&success);`  
  if(`success=true`) iterator (it) is created.  
  if(`success==false`) iterator (it) is not created.  
  
* To `check iterator's position` in Singly Linked List
  ```c
  bool hasNextinSinglylinkedlist(Singlylinkedlistiterator *singlylinkedlistIterator);   
  ```
  `bool check;`  
  `check=hasNextInSinglylinkedlist(&it);`  
  if(`check==true`) next element is exist in the list.  
  if(`check==false`) iterator is at end of the list.  

* To `check iterator's position` in Singly Linked List  
  ```c
  void * getNextElementFromSinglylinkedlist(SinglylinkedlistIterator *singlylinkedlistIterator,bool *success);  
  ```
  In this function iterator will return the current pointing element (address) and traverse one step forward.  
  `void * ptr;`  
  `bool success;`  
  `ptr=getNextElementFromSinglylinkedlist(&it,&success);`  
  if(`success=true`) element is received in ptr.  
  if(`success=false`)  element is not received in ptr.  
  
  ***
### Use Of Singly Linked List :
  ```c
  #include<my_sll.h>
  #include<stdio.h>
  int main()
  {
  int i1,i2,i3;
  int y,*x;
  bool succ;
  Singlylinkedlist *list1;
  list1=createSinglylinkedlist(&succ);
  if(succ==false)
  {
  printf("Unable to create list");
  return 0;
  }
  printf("List Created\n");
  i1=100;
  i2=200;
  i3=300;

  //adding data
  addtoSinglylinkedlist(list1,(void *)&i1,&succ);
  if(succ) printf("%d added to list1\n",i1);
  else printf("Unable to add %d to list1\n",i1);
  //adding data
  addtoSinglylinkedlist(list1,(void *)&i2,&succ);
  if(succ) printf("%d added to list1\n",i2);
  else printf("Unable to add %d to list1\n",i2);
  //inserting data
  insertintoSinglylinkedlist(list1,1,(void *)&i3,&succ);
  if(succ) printf("%d inserted to list1\n",i3);
  else printf("Unable to insert %d to list1\n",i3);
  //size of list
  printf("Size of list1 is %d\n",getsizeOfSinglylinkedlist(list1));

  //use of iterator
  SinglylinkedlistIterator it;
  it=getSinglylinkedlistiterator(list1,&succ);
  if(succ)
  {
  while(hasnextinSinglylinkedlist(&it))
  {
  x=(int *)getnextelementfromSinglylinkedlist(&it,&succ);
  printf("%d\n",*x);
  }
  }
 
  //removing data of 0 index
  x=removefromSinglylinkedlist(list1,0,&succ);
  if(succ) printf("%d removed list1\n",*x);
  else printf("Unable to remove");
 
  //clearing list
  clearSinglylinkedlist(list1);

  //destroying list
  destroySinglylinkedlist(list1);
  return 0;
  }
  ```


## Generic Doubly Linked List
***
### Description of Main functions :

* To `create` DoublyLinkedList
   ```c
   DoublyLinkedList * createDoublyLinkedList(bool *success); 
   ```
   `bool success;`  
    `DoublyLinkedList *list;`  
    `list=createDoublyLinkedList(&success);`   
    if(`success==true`) list created.    
    if(`success==false`) list is not created.  

* To `add` element in Doubly Linked List
  ```c
  void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;`  
  `addToDoublyLinkedList(list,(void *)&i,&success);`  
   if(`success==true`) element is added.  
   if(`success==false`) element is not added.  
    
* To `insert` element in Doubly Linked List
   ```c
   void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);  
   ```
  `bool success;`  
  `int i=100;`  
  `int index;` (position to insert element in list)  
  `insertIntoDoublyLinkedList(list,index,(void *)&i,&success);`  
   if(`success==true`) element is inserted.  
   if(`success==false`) element is not inserted.  
   
* To `remove` element from Doubly Linked List  
  ```c
  void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);  
  ```
  function will return removed element's address.  
  `bool success;`  
  `void * ptr;`  
  `int index;` (position to remove element in list)  
  `ptr=removeFromDoublyLinkedList(list,index,&success);`  
  if(`success==true`) element is removed.  
  if(`success==false`) element is not removed.  

* To `get size` of Doubly Linked List
  ```c
  int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);  
  ```
  `int size;`  
  `size=getSizeOfDoublyLinkedList(list);`  

* To `get an element` from Doubly Linked List    
  ```c
  void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
  ```
  `bool success;`  
  `void * ptr;`  
  `int index;`  
  `ptr=getFromDoublyLinkedList(list,index,&success);`  
  if(`success==true`) element is received in ptr.  
  if(`success==false`) element is not received int ptr.  

* To `merge one list into another list` of Doubly Linked List  
  ```c
  void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,bool *success);
  ```
  we have `list_1` and `list_2` of DoublyLinkedList.    
  for merging `list_1` into `list_2`.  
  `bool success;`  
  `appendToDoublyLinkedList(list_1,list_2,&success);`  
  if(`success=true`) lists are merged.  
  if(`success==false`) lists are not merged.  

* To `clear` the Doubly Linked List  
  ```c
  void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
  ```
  use to free (remove) nodes of list (size of list is zero).  
  `clearDoublyLinkedList(list);`

* To `delete/destroy` the Doubly Linked List    
  ```c
  void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
  ```
  use to delete the list.  
  `destroyDoublyLinkedList(list);`  
  ***
### Description of Iterator functions of Doubly Linked List :  
* To `create iterator` of Doubly Linked List
  ```c
  DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);  
  ```
  `DoublyLinkedListIterator it;`  
  `bool success;`  
  `it=getDoublyLinkedListIterator(list,&success);`  
  if(`success==true`) iterator (it) is created.  
  if(`success==false`) iterator (it) is not created.  
  
* To `check iterator's position` in Doubly Linked List
  ```c
  bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator); 
  ```
  `bool check;`  
  `check=hasNextInDoublyLinkedList(&it);`  
  if(`check==true`) next element is exist in the list.  
  if(`check==false`) iterator is at end of the list.  

* To `check iterator's position` in Doubly Linked List
  ```c
  void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);
  ```
  In this function iterator will return the current pointing element (address) and traverse one step forward.  
  `void * ptr;`  
  `bool success;`  
  `ptr=getNextElementFromDoublyLinkedList(&it,&success);`  
  if(`success==true`) element is received in ptr.  
  if(`success==false`)  element is not received in ptr.  

* To `create reverse iterator` of Doubly Linked List
  ```c
  DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
  ```
  `DoublyLinkedListReverseIterator it;`  
  `bool success;`  
  `it=getDoublyLinkedListReverseIterator(list,&success);`  
  if(`success==true`) reverse iterator (it) is created.  
  if(`success==false`) reverse iterator (it) is not created.  
  
* To `check reverse iterator's position` in Doubly Linked List
  ```c
  bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator); 
  ```
  `bool check;`  
  `check=hasPreviousInDoublyLinkedList(&it);`  
  if(`check==true`) previous element is exist in the list.  
  if(`check==false`) iterator is at start of the list.  

* To `check reverse iterator's position` in Doubly Linked List
  ```c
  void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);
  ```
  In this function iterator will return the current pointing element (data of node) and traverse one step backward.  
  `void * ptr;`  
  `bool success;`  
  `ptr=getPreviousElementFromDoublyLinkedList(&it,&success);`  
  if(`success==true`) element is received in ptr.  
  if(`success==false`)  element is not received in ptr.  
  ***
### Use Of Doubly Linked List :
  ```c
  #include<my_dll.h>
  #include<stdio.h>
  int main()
  {
  int i1,i2,i3;
  int y,*x;
  bool succ;
  DoublyLinkedList *list1;
  list1=createDoublyLinkedList(&succ);
  if(succ==false)
  {
  printf("Unable to create list");
  return 0;
  }
  printf("List Created\n");
  i1=100;
  i2=200;
  i3=300;

  //adding data
  addToDoublyLinkedList(list1,(void *)&i1,&succ);
  if(succ) printf("%d added to list1\n",i1);
  else printf("Unable to add %d to list1\n",i1);
  //adding data
  addToDoublyLinkedList(list1,(void *)&i2,&succ);
  if(succ) printf("%d added to list1\n",i2);
  else printf("Unable to add %d to list1\n",i2);
  //inserting data
  insertIntoDoublyLinkedList(list1,1,(void *)&i3,&succ);
  if(succ) printf("%d inserted to list1\n",i3);
  else printf("Unable to insert %d to list1\n",i3);
  //size of list
  printf("Size of list1 is %d\n",getSizeOfDoublyLinkedList(list1));

  //use of iterator
  //(similarly we can use reverse iterator in it for reverse iteration.)
  DoublyLinkedListIterator it;
  it=getDoublyLinkedListIterator(list1,&succ);
  if(succ)
  {
  while(hasNextInDoublyLinkedList(&it))
  {
  x=(int *)getNextElementFromDoublyLinkedList(&it,&succ);
  printf("%d\n",*x);
  }
  }
 
  //removing data of 0 index
  x=removeFromDoublyLinkedList(list1,0,&succ);
  if(succ) printf("%d removed list1\n",*x);
  else printf("Unable to remove");
 
  //clearing list
  clearDoublyLinkedList(list1);

  //destroying list
  destroyDoublyLinkedList(list1);
  return 0;
  }
  ```

## Generic Stack
___
### Description of Main functions :
* To `create` Stack
  ```c
  Stack * createStack(bool *success);
  ```
  `bool success;`  
  `Stack *stack;`  
  `list=createStack(&success);`  
  if(`success==true`) stack is created.  
  if(`success==false`) stack is not created.  

* To `push` in Stack
  ```c
  void pushonStack(Stack *stack,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;`  
  `pushonStack(stack,(void *)&i,&success);`  
  if(`success==true`) element is pushed.  
  if(`success==false`) element is not pushed.

* To `pop` from Stack
  ```c
  void * popfromStack(Stack *stack,bool *success);
  ```
  `bool success;`  
  `void *ptr;`  
  `popfromStack(stack,&success);`  
  if(`success==true`) element is poped.  
  if(`success==false`) element is not poped.  

* To `get size` of Stack  
  ```c
  int getsizeOfStack(Stack *stack);  
  ```
  `int size;`  
  `size=getsizeofStack(stack);`  

* To `top element` of Stack  
  ```c
  void * elementattopofStack(Stack *stack,bool *success);
  ```
  `bool success;`  
  `void *ptr;`
  `ptr=elementattopofStack(stack,&success);`(ptr is pointing top most element of stack.)  
  if(`success==true`) we got top element.  
  if(`success==true`) we didn't got top element.  
* To `check` is Stack `empty`
  ```c
  bool isStackempty(Stack *stack);
  ```
  `bool check;`  
  `isStackempty(stack);`  
  if(`check==true`) stack is empty.  
  if(`check==false`) stack is not empty.  

* To `clear` the Stack
  ```c
  void clearStack(Stack *stack);
  ```
  use to make stack empty (size of stack is zero).  
  `clearStack(stack);`

* To `delete/destroy` the Stack
  ```c
  void destroyStack(Stack *stack);	
  ```
  use to delete the stack.  
  `destroyStack(stack);`  
  ___
### Use Of Stack :
  ```c
 #include<my_stack.h>
 #include<stdio.h>
 int main()
 {
 int succ;
 int x1,x2,x3,x4,x5;
 int *x;
 x1=100;
 x2=200;
 x3=300;
 x4=400;
 x5=500;
 Stack *stack;
 stack=createStack(&succ);
 if(stack==false)
 {
 printf("Unable to create stack\n");
 return 0;
 }
 // push data on stack
 pushonStack(stack,(void *)&x1,&succ);
 if(succ) printf("element pushed\n");
 pushonStack(stack,(void *)&x2,&succ);
 if(succ) printf("element pushed\n");
 pushonStack(stack,(void *)&x3,&succ);
 if(succ) printf("element pushed\n");
 pushonStack(stack,(void *)&x4,&succ);
 if(succ) printf("element pushed\n");
 pushonStack(stack,(void *)&x5,&succ);
 if(succ) printf("element pushed\n");

 // size of stack
 printf("Size of stack : %d\n",getsizeofStack(stack));

 //checking is stack empty
 if(isStackempty(stack)) printf("Stack is empty\n");
 else printf("Stack is not empty\n");

 //checking top element of stack
 x=(int *)elementattopofStack(stack,&succ); 
 printf("Element at top of stack is %d\n",*x);  

 //poping data from stack
 while(!isStackempty(stack))
 {
 x=(int *)popfromStack(stack,&succ);
 printf("%d popped from stack\n",*x);
 }

 //destorying stack
 destroyStack(stack);
 return 0;
 }
  ```

 ## Generic Queue
___
### Description of Main functions :
* To `create` Queue
  ```c
  Queue * createPQueue(bool *success);
  ```
  `bool success;`  
  `PQueue *pqueue;`  
  `list=createPQueue(&success);`  
  if(`success==true`) queue created.  
  if(`success==false`) queue is not created.  

* To `Add` in Queue
  ```c
  void AddtoPQueue(Queue *queue,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;`  
  `AddtoPQueue(queue,(void *)&i,&success);`  
  if(`success==true`) element is added.  
  if(`success==false`) element is not added.

* To `remove` from Queue
  ```c
  void * removefromPQueue(Queue *queue,bool *success);
  ```
  `bool success;`  
  `void *ptr;`  
  `removefromPQueue(queue,&success);`  
  if(`success==true`) element is removed.  
  if(`success==false`) element is not removed.  

* To `get size` of Queue  
  ```c
  int getsizeofPQueue(Queue *queue);  
  ```
  `int size;`  
  `size=getsizeofPQueue(queue);`  

* To `top element` of Queue  
  ```c
  void * ElementAtFrontOfPQueue(Queue *queue,bool *success);
  ```
  `bool success;`  
  `void *ptr;`
  `ptr=ElementAtFrontOfPQueue(queue,&success);`(ptr is pointing top most element of queue.)  
  if(`success==true`) we got top element.  
  if(`success==true`) we didn't got top element.  
* To `check` is Queue `empty`
  ```c
  bool isPQueueEmpty(Queue *queue);
  ```
  `bool check;`  
  `isPQueueEmpty(queue);`  
  if(`check==true`) queue is empty.  
  if(`check==false`) queue is not empty.  

* To `clear` the Queue
  ```c
  void clearPQueue(Queue *queue);
  ```
  use to make queue empty (size of queue is zero).  
  `clearPQueue(queue);`

* To `delete/destroy` the Queue
  ```c
  void destroyPQueue(Queue *queue);	
  ```
  use to delete the queue.  
  `destroyPQueue(queue);`  
  ___
### Use Of Queue :
  ```c
  #include<stdio.h>
  #include<my_pqueue.h>
  int comparator(void *left, void *right)
  {
  int *leftInt;
  int *rightInt;
  leftInt = (int*)left;
  rightInt = (int*)right;
  return (*leftInt) - (*rightInt);
  }

  int main()
  {
  int x1, x2, x3, x4, x5;
  int succ;
  int *ptr;
  PQueue *pqueue;  
  pqueue = createPQueue( comparator , &succ);
  if(!succ)
  {
  printf("Low memory issue\n");
  return 0;
  }
  x1=10;
  x2 =20;
  x3= 34;
  x4 = 40;
  x5 = 47;
  AddtoPQueue(pqueue , &x1 , &succ);
  AddtoPQueue(pqueue , &x2 , &succ);
  AddtoPQueue(pqueue , &x3 , &succ);
  AddtoPQueue(pqueue , &x4 , &succ);
  AddtoPQueue(pqueue , &x5 , &succ);
  while(getsizeofPQueue(pqueue)>0)
  {
  ptr = ElementAtFrontOfPQueue(pqueue , &succ);
  //checking is queue empty
  if(isPQueueEmpty(queue)) printf("Queue is empty\n");
  else printf("Queue is not empty\n");
  
   
  //removing from queue
  while(!isPQueueEmpty(pqueue)) 
  {
  x=(int *)removefromPQueue(pqueue,&succ);
  printf("%d removed from queue\n",*x);
  }
  //destoring queue 
  destroyPQueue(pqueue);
  return 0;
  }
  ```  

  ## Generic AVL Tree
___
### Description of Main functions :
* To `create` AVL Tree  
  ```c
  AVLTree * createAVLTree(bool *success,int (*predicate)(void *,void *));
  ```
  here the predicate funtion is required to create AVLTree (comparator funtion).  
  `bool success;`  
  `AVLTree *tree;`  
  `tree=createAVLTree(&success,predicate);`  
  if(`success==true`) tree is created.  
  if(`success==false`) tree is not created.  
* To `add/insert` in AVL Tree
  ```c
  void addtoAVLTree(AVLTree *avltree,void *ptr,bool *success);  

  void insertintoAVLTree(AVLTree *avltree,void *ptr,bool *success);
  ```
  both the funtions are use for adding and inserting new data in AVL Tree.  
  `bool success;`  
  `int i=100;`  
  `addtoAVLTree(tree,(void *)&i,&success);`  
   if(`success==true`) element is added.  
   if(`success==false`) element is not added.  
   similary we can use insertintoAVLTree function.  
* To `get size` of AVL Tree
  ```c
  int getsizeOfAVLTree(AVLTree *avltree);
  ```
  `int size;`  
  `size=getsizeOfAVLTree(tree);`  
* To `remove` element from AVL Tree
  ```c
  void * removefromAVLTree(AVLTree *avltree,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;` (element to remove from tree)  
  `void *ptr;`  
  `ptr=removefromAVLTree(avltree,(void *)i,&success);` (ptr will store the address of removed element, which is i)  
  if(`success==true`) element is removed.  
  if(`success==false`) element is not removed.  

* To `get an element` from AVL Tree  
  ```c
  void * getfromAVLTree(AVLTree *avltree,void *ptr,bool *success);
  ```
  `bool success;`  
  `int i=100;` (element to get from tree)  
  `void *ptr;`  
  `ptr=removefromAVLTree(avltree,(void *)i,&success);` (ptr will store the address of element to get, which is i)  
  if(`success==true`) element is received in ptr.  
  if(`success==false`) element is not received int ptr.  
* To `get height` of AVL Tree
  ```c
  int getheightOfAVLTree(AVLTreeNode *root);
  ```
  `int height;`  
  `getheightOfAVLTree(avltree);`  
* To `clear` the AVL Tree  
  ```c
  void clearAVLTree(AVLTree *avltree);
  ```
  use to free (remove) all nodes of tree (size of tree is zero).  
  `clearAVLTree(tree);`  
* To `delete/destroy` the AVL Tree  
  ```c
  void destroyAVLTree(AVLTree *avltree);
  ```
  use to delete the tree.  
  `destroyAVLTree(tree);`  
  ***  
### Description of Iterator functions of AVL Tree:  

* To `create iterator` of AVLTree
  ```c
  AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avltree,bool *success);  

  AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avltree,bool *success);  

  AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avltree,bool *success);  
  ```
  `AVLTreeInOrderIterator it;`  
  `bool success;`  
  `it=getAVLTreeInOrderIterator(tree,&success);`  
  if(`success=true`) iterator (it) is created.  
  if(`success==false`) iterator (it) is not created.  
  similary we can create iterator for pre order and post order traversal.
  
* To `check iterator's position` in AVL Tree  
  ```c
  bool HasNextInOrderelementAVLTree(AVLTreeInOrderIterator *avltreeInOrderIterator);  
  
  bool HasNextPreOrderelementAVLTree(AVLTreePreOrderIterator *avltreePreOrderIterator);  

  bool HasNextPostOrderelementAVLTree(AVLTreePostOrderIterator *avltreePostOrderIterator);  
  ```
  `bool check;`  
  `check=HasNextInOrderElementInAVLTree(&it);`  
  if(`check==true`) next element is exist in the tree traversal.  
  if(`check==false`) iterator is at end of the tree traversal.  
  similary we can use pre order and post order function.  

* To `check iterator's position` in AVL Tree  
  ```c
  void * getnextInOrderelementfromAVLTree(AVLTreeInOrderIterator *avltreeInOrderIterator,bool *success);  

  void * getnextPreOrderelementfromAVLTree(AVLTreePreOrderIterator *avltreePreOrderIterator,bool *success);  

  void * getnextPostOrderelementfromAVLTree(AVLTreePostOrderIterator *avltreePostOrderIterator,bool *success);  
  ```
  In this function iterator will return the current pointing element (data of node) and traverse one step forward.  
  `void * ptr;`  
  `bool success;`  
  `ptr=getnextInOrderelementfromAVLTree(&it,&success);`  
  if(`success=true`) element is received in ptr.  
  if(`success=false`)  element is not received in ptr.  
  similary we can use pre order and post order function.  
  ***
### Use Of AVL Tree :
```c
#include<my_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}

int main()
{
char more;
int *x;
int num,ch;
AVLTree *tree;
AVLTreeInOrderIterator inOrderIterator;
AVLTreePreOrderIterator preOrderIterator;
AVLTreePostOrderIterator postOrderIterator;

bool succ;
tree=createAVLTree(&succ,myComparator);
if(succ==false)
{
printf("Unable to create tree, low on memory\n");
return 0;
}
while(1)
{
printf("1. Insert \n");
printf("2. In order traversal\n");
printf("3. Pre order traversal\n");
printf("4. Post order Traversal\n");
printf("5. Remove \n");
printf("6. Search \n");
printf("7. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter number to be insert in tree  : ");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertintoAVLTree(tree,x,&succ);
if(succ) printf("address of item that contain %d inserted in tree\n",*x);
else printf("Unable to insert in tree\n"); 
}
if(ch==2)
{
printf("In Order Iteration start \n");
inOrderIterator=getAVLTreeInOrderIterator(tree,&succ);
if(succ)
{
while(HasnextInOrderelementAVLTree(&inOrderIterator))
{
x=(int *)getnextInOrderelementfromAVLTree(&inOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==3)
{
printf("Pre Order Iteration start \n");
preOrderIterator=getAVLTreePreOrderIterator(tree,&succ);
if(succ)
{
while(HasnextPreOrderelementinAVLTree(&preOrderIterator))
{
x=(int *)getnextPreOrderelementfromAVLTree(&preOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==4)
{
printf("Post Order Iteration start \n");
postOrderIterator=getAVLTreePostOrderIterator(tree,&succ);
if(succ)
{
while(HasnextPostOrderelementAVLTree(&postOrderIterator))
{
x=(int *)getnextPostOrderelementfromAVLTree(&postOrderIterator,&succ);
printf("%d\n",*x);
}
}
}
if(ch==5)
{
printf("Enter number to remove : ");
scanf("%d",&num);
fflush(stdin);
x=removefromAVLTree(tree,&num,&succ);
if(succ) printf("%d is removed\n",*x);
else printf("%d is not found\n",num);
}
if(ch==6)
{
printf("Enter number to search : ");
scanf("%d",&num);
fflush(stdin);
x=getfromAVLTree(tree,&num,&succ);
if(succ) printf("%d is found\n",*x);
else printf("%d is not found\n",num);
}
if(ch==7) break;
}//main loop ends
destroyAVLTree(tree); 
return 0;
}
```



## Generic Heap
___
### Description of Main functions :
* To `create` Heap
  ```c
  Heap *createHeap(int (*comparator)(void* , void*) , int *success)
  ```
  `bool success;`  
  `Heap *heap;`  
  `heap = createHeap(comparator ,&succ);`  
  if(`succ==true`) heap is created.  
  if(`succ==false`) heap is not created.  


* To `Add To` Heap
  ```c
  void addtoHeap( Heap *heap , void *element, int *success)

  ```
  `bool success;`  
  `int x;`
   x =100;
  `addtoHeap(heap , (void *)&x1 , &succ);`  
   if(`succ==true`)  Element is Added.  
   if(`succ==false`) Element is not Added.  

* To ` Remove From` Heap
  ```c
   void *removefromHeap(Heap *heap , int *success)
   ```
  `bool success;`  
  `void *ptr;`  
  `removefromHeap(heap , &success);`  
   if(`success==true`) element is removed.  
   if(`success==false`) element is not removed.  



* To `get Element` from Heap
  ```c
  void *getElementfromHeap(Heap *heap , int index  , int *success)
  ```
  `bool success;`  
  `void *ptr;`  
  `ptr = getElementfromHeap(heap , i , &succ);`  
  if(`success==true`)   
  if(`success==false`)  

* To `Update Element` in Heap
  ```c
  void updateElementinHeap(Heap *heap , int index , void *element , int *success)

  ```
  `bool success;`  
  `int x =200; `
  `updateElementinHeap(heap , 0 , (void *)&x , &succ);`if(`success==true`)   
  
  if(`success==true`) Element is Updated   
  if(`success==false`) Element is not Updated 
  ### Use of Heap :
  ```c
  #include<stdio.h>
  #include<my_heap.h>
  int comparator(void *left, void *right)
  {
  int *leftInt;
  int *rightInt;
  leftInt = (int*)left;
  rightInt = (int*)right;
  return (*leftInt) - (*rightInt);
  }

  int main()
  {
  Heap *heap;
  int succ;
  int x1, x2, x3, x4,x5,x6,x7;
  int *ptr;
  int i;
  x1 =10; 
  x2= -3;
  x3 = 44;
  x4 = 5;
  x5 = 60;
  x6 = 4;
  heap = createHeap(comparator ,&succ);
  addtoHeap(heap , (void *)&x1 , &succ);
  addtoHeap(heap , (void *)&x2 , &succ);
  addtoHeap(heap , (void *)&x3 , &succ);
  addtoHeap(heap , (void *)&x4 , &succ);
  addtoHeap(heap , (void *)&x5 , &succ);
  addtoHeap(heap , (void *)&x6 , &succ);
  for( i =0; i<getsizeofHeap(heap); i++)
  {
  ptr = getElementfromHeap(heap , i , &succ);
  printf("%d\n" , *ptr);
  }
  printf("Now updating\n");
  x7 =200;
  updateElementinHeap(heap , 0 , (void *)&x7 , &succ);
  for(i=0;  i<getsizeofHeap(heap); i++)
  {
  ptr = getElementfromHeap(heap , i ,&succ);
  printf("%d\n" , *ptr);
  }
  return 0;
  }
  ```



































##  Generic Array
___
### Description of Main functions :
* To `create` Array
  ```c
  Array * createArray(bool *success);
  ```
  `bool success;`  
  `Array array;`  
  `list=createArray(&success);`  
  if(`success==true`) Array is created.  
  if(`success==false`) Array is not created.  


* To `get size` of Array 
  ```c
  int getsizeofArray(Array *array);  
  ```
  `int size;`  
  `size=getsizeofArray(array);`  

* To `set Element ` of Array 
  ```c
void setelementofArray(Array *array , int index , void *element,int *success)
  ```
  `bool success;`  
  `void *ptr;`
  `ptr = setelementofArray(array , 2,(void*)&x1 , &succ);`(set element of Array.)  
  if(`success==true`) we set element of Array.  
  if(`success==false`) we didn't set element of Array.  

* To `get Element ` of Array 
  ```c
void *getelementofArray(Array *array, int index)
  ```
  `bool success;`  
  `void *ptr;`
  ` ptr=(int *)getelementofArray(array ,i);;`(ptr is pointing get element of array )  
  if(`success==true`) we get element of Array.  
  if(`success==false`) we didn't get element of Array.  

  ___

### Use of Array :
  ```c
  #include<my_array.h>
  #include<stdio.h>
  int main ()
  {
  int i;
  Array *array;
  int succ;
  int *ptr;
  int x1, x2, x3;
  array = createArray(&succ);
  if(!succ)
  {
  printf("Unable to allocate memory\n");
  return 0;
  }
  x1 = 100;
  x2 = 200;
  x3= 300;
  setelementofArray(array , 2,(void*)&x1 , &succ);
  setelementofArray(array , 25,(void*)&x2 , &succ);
  setelementofArray(array , 32,(void*)&x3 , &succ);
  for( int i=0; i<getsizeofArray(array); i++)
  {
  ptr=(int *)getelementofArray(array ,i);
  if(ptr!=NULL) printf("(%d--->%d)", i , *ptr);
  else printf("(%d--->)", i);
  }
  return 0;
  }
  ```



