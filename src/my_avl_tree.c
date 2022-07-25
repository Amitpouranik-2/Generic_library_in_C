#ifndef __MY_AVL_TREE__C
#define __MY_AVL_TREE__C 123
#include <stdlib.h>
#include <my_avl_tree.h>
#include <my_stack.h>
AVLTree *createAVLTree(bool *success, int (*predicate)(void *, void *))
{ 
if (success)*success = false;
AVLTree *avltree;
avltree = (AVLTree *)malloc(sizeof(AVLTree));
if (avltree == NULL || predicate == NULL)return NULL;
avltree->start = NULL;
avltree->predicate = predicate;
avltree->size = 0;
if (success)*success = true;
return avltree;
}
int getsizeofAVLTree(AVLTree *avltree)
{
if (avltree == NULL)
return 0;
return avltree->size;
}
void destroyAVLTree(AVLTree *avltree)
{
if (avltree == NULL)return;
clearAVLTree(avltree);
free(avltree);
}
void clearAVLTree(AVLTree *avltree)
{
}
void insertintoAVLTree(AVLTree *avltree, void *ptr, bool *success)
{
int succ;
Stack *stack;
AVLTreeNode *t, *j;
int weight;
if (success)*success = false;
if (avltree == NULL)return;
if (avltree->start == NULL)
{
t = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if (t == NULL)return;
t->ptr = ptr;
t->left = NULL;
t->right = NULL;
avltree->start = t;
avltree->size++;
if (success)*success = true;
return;
}
stack=createStack(&succ);
if(succ==false) return;
j = avltree->start;
while (1)
{
weight = avltree->predicate(ptr, j->ptr);
 if (weight == 0)
{
return;
}
pushonStack(stack,j,&succ);
if(succ==false)
{
destroyStack(stack);
return;
}
if (weight < 0)
{           
if (j->left == NULL)
{
t = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if (t == NULL)return;
t->ptr = ptr;
t->left = NULL;
t->right = NULL;
j->left = t;
break;
}
else
{
j = j->left;
}
}
else
{
if (j->right == NULL)
{
t = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
if (t == NULL) return;
t->ptr = ptr;
t->left = NULL;
t->right = NULL;
j->right = t;
break;
}           
else
{
j = j->right;
}
}
}
if (success)*success = true;
avltree->size++;
BalanceAVLtree(avltree,stack);
destroyStack(stack);
}
void *getfromAVLTree(AVLTree *avltree, void *ptr, bool *success)
{
int weight;
AVLTreeNode *t;
if (success)*success = false;
if (avltree == NULL || avltree->start == NULL)return NULL;
t = avltree->start;
while (t != NULL)
{
weight = avltree->predicate(ptr, t->ptr);
if (weight == 0)
{
if (success)*success = true;
return t->ptr;
}
if (weight < 0)
{
t = t->left;
}
else
{
t = t->right;
}
}
return NULL;
}
void *removefromAVLTree(AVLTree *avltree, void *ptr, bool *success)
{
AVLTreeNode *t, *j, *e, *f;
AVLTreeNode **p2p;
int *foundPtr;
int weight;
if (success)*success = false;
if (avltree == NULL || avltree->start == NULL)return NULL;
t = avltree->start;
while (t != NULL)
{
weight = avltree->predicate(ptr, t->ptr);
if (weight == 0) break;
j = t;
if (weight < 0)t = t->left;
else t = t->right;
}
if (t == NULL) return NULL;
foundPtr = t->ptr;
if (t == avltree->start)p2p = &(avltree->start);
else if (j->left == t)p2p = &(j->left);
else if (j->right == t)p2p = &(j->right);
if (t->left == t->right)
{
*p2p = NULL;
}
else
{
if (t->right != NULL)
{
for (e = t->right; e->left != NULL; e = e->left)f = e;
if (e == t->right)
{
e->left = t->left;
}
else
{
f->left = e->right;
e->left = t->left;
e->right = t->right;
}
*p2p = e;
}
else
{
for (e = t->left; e->right != NULL; e = e->right)
if (e == t->left)
{
e->right = t->right;
}
else
{
f->right = e->right;
e->left = t->left;
e->right = t->right;
}
*p2p = e;
}
}
free(t);
avltree->size--;
if (success)*success = true;
return foundPtr;
}

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avltree, bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreeInOrderIterator avltreeinorderiterator;
avltreeinorderiterator.node = NULL;
avltreeinorderiterator.stack = NULL;
if (success)*success = false;
if (avltree == NULL) return avltreeinorderiterator;
if (avltree->start == NULL)
{
if (success)*success = true;
return avltreeinorderiterator;
}
avltreeinorderiterator.stack = createStack(&succ);
if (succ == false) return avltreeinorderiterator;
t = avltree->start;
while (t != NULL)
{
pushonStack(avltreeinorderiterator.stack, (void *)t, &succ);
if (succ == false)
{
destroyStack(avltreeinorderiterator.stack);
avltreeinorderiterator.stack = NULL;
return avltreeinorderiterator;
}
t = t->left;
}
avltreeinorderiterator.node = (AVLTreeNode *)popfromStack(avltreeinorderiterator.stack, &succ);
if (success)*success = true;
return avltreeinorderiterator;
}
bool HasNextInorderelementAVLTree(AVLTreeInOrderIterator *avltreeinorderiterator)
{
if (avltreeinorderiterator == NULL || avltreeinorderiterator->node == NULL)
return false;
return true;
}
void *getnextinorderelementfromAVLTree(AVLTreeInOrderIterator *avltreeinorderiterator, bool *success)
{
AVLTreeNode *j, *t;
int succ;
if (success)*success = false;
if (avltreeinorderiterator == NULL)return NULL;
if (avltreeinorderiterator->node == NULL)return NULL;
j = avltreeinorderiterator->node;
t = j->right;
while (t != NULL)
{
pushonStack(avltreeinorderiterator->stack, (void *)t, &succ);
if (succ == false)
{
destroyStack(avltreeinorderiterator->stack);
avltreeinorderiterator->stack = NULL;
avltreeinorderiterator->node = NULL;
if (success)*success = true;
return j->ptr;
}
t = t->left;
}
if (isStackempty(avltreeinorderiterator->stack))
{
destroyStack(avltreeinorderiterator->stack);
avltreeinorderiterator->node = NULL;
avltreeinorderiterator->stack = NULL;
}
else
{
avltreeinorderiterator->node = (AVLTreeNode *)popfromStack(avltreeinorderiterator->stack, &succ);
}
if (success)*success = true;
return j->ptr;
}
int getheightofAVLTree(AVLTreeNode *root)
{
int leftHeighttree, rightHeighttree;
if (root == NULL)return 0;
leftHeighttree = getheightofAVLTree(root->left);
rightHeighttree = getheightofAVLTree(root->right);
return (leftHeighttree > rightHeighttree) ? leftHeighttree + 1 : rightHeighttree + 1;
}
void BalanceAVLtree(AVLTree *avltree , Stack *stack)
{
AVLTreeNode **p2p;
AVLTreeNode *lc,*rc,*root,*lcrc,*rclc,*parent;
int lh,diff,rh,succ;
if(stack==NULL) return;
if(isStackempty(stack)) return;
while(! isStackempty(stack))
{
root=popfromStack(stack,&succ);
lh=getheightofAVLTree(root->left);
rh=getheightofAVLTree(root->right);
diff=lh-rh;
if(diff>=-1 && diff<=1) continue;
if(isStackempty(stack))
{
p2p=&(avltree->start);
}
else
{
parent=elementattopofStack(stack,&succ);
if(parent->left==root)
{
p2p=&(parent->left);
}
else
{
p2p=&(parent->right);
}
}
if(rh>lh)
{
rc=root->right;
if(getheightofAVLTree(rc->left)>getheightofAVLTree(rc->right))
{
rclc=rc->left;
rc->left=rclc->right;
rclc->right=rc;
root->right=rclc;
rc=root->right;
}
root->right=rc->left;
rc->left=root;
*p2p=rc;
}
else
{
lc=root->left;
if(getheightofAVLTree(lc->right)>getheightofAVLTree(lc->left))
{
lcrc=lc->right;
lc->right=lcrc->left;
lcrc->left=lc;
root->left=lcrc;
lc=root->left;
}
root->left=lc->right;
lc->right=root;
*p2p=lc;
}
}// stack empty loop ends
}
AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avltree, bool *success)
{
int succ;
AVLTreeNode *t; 
AVLTreePreOrderIterator avltreepreorderiterator;
avltreepreorderiterator.node = NULL;
avltreepreorderiterator.stack = NULL;
if (success)*success = false;
if (avltree == NULL)
return avltreepreorderiterator;
if (avltree->start == NULL)
{
if (success)*success = true;
return avltreepreorderiterator;
}
avltreepreorderiterator.stack =createStack(&succ);
if (succ == false)
return avltreepreorderiterator;
avltreepreorderiterator.node = avltree->start;
if (success)*success = true;
return avltreepreorderiterator;
}
bool HasNextPreorderelementAVLTree(AVLTreePreOrderIterator *avltreepreorderiterator)
{
if (avltreepreorderiterator == NULL || avltreepreorderiterator->node == NULL)
return false;
return true;
}
void *getnextPreorderelementfromAVLTree(AVLTreePreOrderIterator *avltreepreorderiterator, bool *success)
{
AVLTreeNode *t, *j;
int succ;
if (success)*success = false;
if(avltreepreorderiterator == NULL)
return NULL;
if (avltreepreorderiterator->node == NULL)
return NULL;
j = avltreepreorderiterator->node;
if (j->right != NULL)
{
pushonStack(avltreepreorderiterator->stack, (void *)j->right, &succ);
if (succ == false)
{
destroyStack(avltreepreorderiterator->stack);
avltreepreorderiterator->stack == NULL;
avltreepreorderiterator->node == NULL;
if (success)*success = true;
return j->ptr;
}
}
if (j->left != NULL)
{
pushonStack(avltreepreorderiterator->stack, (void *)j->left, &succ);
if (succ == false)
{
destroyStack(avltreepreorderiterator->stack);
avltreepreorderiterator->stack == NULL;
avltreepreorderiterator->node == NULL;
if (success)*success = true;
return j->ptr;
}
}
if (isStackempty(avltreepreorderiterator->stack))
{
destroyStack(avltreepreorderiterator->stack);
avltreepreorderiterator->node = NULL;
avltreepreorderiterator->stack = NULL;
}
else
{
avltreepreorderiterator->node = (AVLTreeNode *)popfromStack(avltreepreorderiterator->stack, &succ);
}
if (success) *success = true;
return j->ptr;
}


AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avltree, bool *success)
{
int succ;
AVLTreeNode *t;
AVLTreePostOrderIterator avltreepostorderiterator;
avltreepostorderiterator.node = NULL;
avltreepostorderiterator.stack = NULL;
if (success)*success = false;
if (avltree == NULL)
return avltreepostorderiterator;
if (avltree->start == NULL)
{
if (success)*success = true;
return avltreepostorderiterator;
}
avltreepostorderiterator.stack = createStack(&succ);
if (succ == false)
return avltreepostorderiterator;
t = avltree->start;
while (1)
{
while (t != NULL)
{
if (t->right != NULL)
{
pushonStack(avltreepostorderiterator.stack, t->right, &succ);
}
pushonStack(avltreepostorderiterator.stack, t, &succ);
 t = t->left;
}
 t = popfromStack(avltreepostorderiterator.stack, &succ);
if (!isStackempty(avltreepostorderiterator.stack) && t->right != NULL && t->right == elementattopofStack(avltreepostorderiterator.stack, &succ))
{
popfromStack(avltreepostorderiterator.stack, &succ);
pushonStack(avltreepostorderiterator.stack, t, &succ);
t = t->right;
}
else
{
break;
}
}
avltreepostorderiterator.node = t;
if (success)*success = true;
return avltreepostorderiterator;
}
bool HasNextPostorderelementAVLTree(AVLTreePostOrderIterator *avltreepostorderiterator)
{
if (avltreepostorderiterator == NULL || avltreepostorderiterator->node == NULL)
return false;
return true;
}
void *getnextPostorderelementfromAVLTree(AVLTreePostOrderIterator *avltreepostorderiterator, bool *success)
{
AVLTreeNode *t, *j;
int succ;
if (success)*success = false;
if (avltreepostorderiterator == NULL)return NULL;
if (avltreepostorderiterator->node == NULL)
return NULL;
j = avltreepostorderiterator->node;
if (isStackempty(avltreepostorderiterator->stack))
{
avltreepostorderiterator->node = NULL;
destroyStack(avltreepostorderiterator->stack);
if (success)*success = true;
return j->ptr;
}
t = NULL;
while (1)
{
while (t != NULL)
{
if (t->right != NULL)
{
pushonStack(avltreepostorderiterator->stack, t->right, &succ);
}
pushonStack(avltreepostorderiterator->stack, t, &succ);
t = t->left;
}
t = popfromStack(avltreepostorderiterator->stack, &succ);
if (!isStackempty(avltreepostorderiterator->stack) && t->right != NULL && t->right == elementattopofStack(avltreepostorderiterator->stack, &succ))
{
popfromStack(avltreepostorderiterator->stack, &succ);
pushonStack(avltreepostorderiterator->stack, t, &succ);
t = t->right;
}
else
{
break;
}
}
avltreepostorderiterator->node = t;
if (success)*success = true;
return j->ptr;
}
#endif