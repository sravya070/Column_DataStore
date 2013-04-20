#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

//void insert_into_bst(node *,char [],int);
//node* create_bst(char [],int);
typedef struct bst_node
{
        char data[100];
	int offset;
	int flag;
        struct bst_node *left;
        struct bst_node *right;
	struct bst_node *parent;
        
}bst_node;















































