#include <my_avl_tree.h>
#include <stdio.h>
#include <stdlib.h>
int myComparator(void*left , void * right )
{
int *leftint ,*rightint;
leftint = (int*)left;
rightint = (int*)right;
return (*leftint)-(*rightint);
}
int main ()
{
AVLTreeInOrderIterator inorderiterator;
AVLTreePreOrderIterator preorderiterator;
AVLTreePostOrderIterator postorderiterator;
int ch;
int *x;
int num;
AVLTree *tree;
int success;

tree = createAVLTree(&success , myComparator);
if(success == false)
{
printf("Unable to create tree  , low on memory\n");
return 0;
}
while(1)
{
printf("1. insert \n");
printf("2. In Order Traversal\n");
printf("3. Remove\n");
printf("4. Search\n");
printf("5. Pre order Traversal\n");
printf("6. post order traversal\n");
printf("7. EXIT\n");
printf("Enter your choice :");
scanf("%d", &ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number to be inserted in  tree\n:");
scanf("%d", &num);
fflush(stdin);
x= (int *)malloc(sizeof(int));
*x= num;
insertintoAVLTree(tree,(void*)x , &success);
if(success) printf("Address of item that contain %d inserted in tree\n", *x);
else printf("Unable to insert into tree\n");
}
if(ch==2)
{
printf(" Inorder iteration starts\n ");
inorderiterator = getAVLTreeInOrderIterator(tree, &success);
if(success)
{
while( HasNextInorderelementAVLTree(&inorderiterator))
{
x= (int*)getnextinorderelementfromAVLTree(&inorderiterator , &success);
printf("%d\n", *x);
}
}
}

if(ch==3)
{
printf(" Enter Number to Remove :");
scanf("%d", &num);
fflush(stdin);
x= removefromAVLTree(tree,&num,&success);
if(success) printf("%d found and remove\n", *x);
else printf("%d is not found \n", num);
}
if(ch==4)
{
printf(" Enter the number to Search :");
scanf("%d", &num);
fflush(stdin);
x = getfromAVLTree(tree, &num , &success);
if(success) printf("%d found \n", *x);
else printf("%d not found \n" , num);
}

if(ch==5)
{
printf(" Pre Order iteration starts \n");
preorderiterator = getAVLTreePreOrderIterator(tree, &success);
if(success)
{
while(HasNextPreorderelementAVLTree(&preorderiterator))
{
x = (int*)getnextPreorderelementfromAVLTree(&preorderiterator , &success);
printf("%d\n", *x);
}
}
}

if(ch==6)
{
printf(" Post Order iteration starts \n");
postorderiterator = getAVLTreePostOrderIterator(tree, &success);
if(success)
{
while(HasNextPostorderelementAVLTree(&postorderiterator))
{
x = (int*)getnextPostorderelementfromAVLTree(&postorderiterator , &success);
printf("%d\n", *x);
}
}
}

if(ch==7) break;
}
destroyAVLTree(tree);
return 0;
}

