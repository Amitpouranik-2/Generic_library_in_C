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
printf("Size of list1 is %d\n",getsizeofSinglylinkedlist(list1));

//use of iterator
Singlylinkedlistiterator it;
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