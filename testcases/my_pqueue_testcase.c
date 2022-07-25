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
printf("ddd");
printf("%d\n" , *ptr);
printf("qq");
} 
printf("b");
return 0;
}