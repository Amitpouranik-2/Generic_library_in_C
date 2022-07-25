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














