#ifndef __MY_AVL_TREE__H
#define __MY_AVL_TREE__H 123
#include<my_common.h>
#include<my_stack.h>
typedef struct __$_my_avl_tree_node
{
void *ptr;
struct __$_my_avl_tree_node *left;
struct __$_my_avl_tree_node *right;
}AVLTreeNode;
typedef struct __$_my_avl_tree
{
struct __$_my_avl_tree_node *start;
int (*predicate)(void * , void *);
int size;
}
AVLTree;

typedef struct  __$_my_avl_tree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
} 
AVLTreeInOrderIterator;

typedef struct  __$_my_avl_tree_Pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}
AVLTreePreOrderIterator;


typedef struct  __$_my_avl_tree_Post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}
AVLTreePostOrderIterator;

AVLTree *createAVLTree(bool *success , int (*predicate) (void * , void *));
void destroyAVLTree(AVLTree *avltree);
int getsizeofAVLTree(AVLTree *avltree);
void clearAVLTree(AVLTree *avltree);
void insertintoAVLTree(AVLTree *avltree , void *ptr, bool *success);
void *removefromAVLTree(AVLTree *avltree , void *ptr , bool *success);
void *getfromAVLTree(AVLTree *avltree, void *ptr , bool *success);
AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *avltree , bool *success);
bool HasNextInorderelementAVLTree(AVLTreeInOrderIterator *avltreeinorderiterator);
void * getnextinorderelementfromAVLTree (AVLTreeInOrderIterator *avltreeinorderiterator, bool *success);

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *avltree , bool *success);
bool HasNextPreorderelementAVLTree(AVLTreePreOrderIterator *avltreepreorderiterator);
void * getnextPreorderelementfromAVLTree (AVLTreePreOrderIterator *avltreepreorderiterator, bool *success);


AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *avltree , bool *success);
bool HasNextPostorderelementAVLTree(AVLTreePostOrderIterator *avltreepostorderiterator);
void * getnextPostorderelementfromAVLTree (AVLTreePostOrderIterator *avltreepostorderiterator, bool *success);

int getheightofAVLTree(AVLTreeNode *root);
void BalanceAVLtree(AVLTree *avltree , Stack *stack);

#endif