#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include"cds.h"
#include"stack.h"
extern int count;
bst_node* insert_into_bst(bst_node *,char [],struct stack * s);
bst_node* create_bst(char [],int);
void inorder(bst_node *);
bst_node *delete_bst(bst_node *head,char name[]);
void transplant(bst_node *head,bst_node *u,bst_node *v);
bst_node *min_bst(bst_node *head);
bst_node *max_bst(bst_node *head);
/*int LoadFromFile(struct stack * s)
{
	FILE * fp;
	int n;
	char buffer[cdsdetail.filedetails[0].size];
	fp=fopen(cdsdetail.datafiles[0],"rb");
	if(fp==NULL) return 0;
	if(count==0)
	{
		cdsdetail.rootNode=NULL;
	}
	while(1)
	{
		if((n=fread(buffer,cdsdetail.filedetails[0].size,1,fp))!=0)
		{
		cdsdetail.rootNode=insert_into_bst(cdsdetail.rootNode,buffer,s);
		//printf("%s\n",cdsdetail.rootNode->data);
		}
		else 
		{		
			break;	
		}
	}
	
	fclose(fp);	
	return 1;
}*/
bst_node *insert_into_bst(bst_node *head,char data[],struct stack * s)
{
	extern int count,data_offset;
	int delete_offset;
	bst_node *temp,*p,*q;
        temp=NULL;
        p=head;
	if(s->top!=0)
	{
		delete_offset=pop(s);
		//printf("inside delete_offset.... %d\n",delete_offset);
		data_offset=delete_offset;
		q=create_bst(data,delete_offset);
	}
	else
	{				
	count++;
	data_offset=count;
        q=create_bst(data,count);
	}
        while(p != NULL)
        {
                temp=p;
                if(strcmp(q->data,p->data) < 0)
                        p=p->left;
                else
                        p=p->right;
        }
        q->parent=temp;
        if(temp == NULL)
                head = q;
        else if(strcmp(q->data,temp->data) < 0)
                temp->left = q;
        else
                temp->right = q;
        return head;

}

bst_node *create_bst(char name[],int count)
{
        bst_node *temp;
        int i=0;
        temp=(bst_node *)malloc(sizeof(bst_node));
	strcpy(temp->data,name);   
        temp->left=NULL;
        temp->right=NULL;
        temp->parent=NULL;
	temp->offset=count;
	temp->flag=0;
        return temp;
}

void inorder(bst_node *head)
{
        if(head == NULL);
        else
        {
                inorder(head->left);
                printf("%s-----%d\n",head->data,head->offset);
                inorder(head->right);
        }
}

bst_node *search_bst(bst_node *head,char name[])
{
        bst_node *temp;       
	if((head==NULL)||(strcmp(head->data,name)==0))
	{			
		return head;
	}        
	if(strcmp(head->data,name) > 0)
	{                
		temp=search_bst(head->left,name);
	}
        else 
	{               
		temp=search_bst(head->right,name);
	}
        return temp;
}
/*bst_node *delete_bst(bst_node *head,char name[])
{
	bst_node *temp,*min;
	temp = (bst_node *)search_bst(head,name);
	printf("%s\n",temp->data);
	printf("inside delete_bst\n");
	if(temp->left == NULL)
	transplant(head,temp,temp->right);
	else if(temp->right == NULL)
	transplant(head,temp,temp->right);
	else
	{
		min=min_bst(temp->right);
		if(min->parent != temp)
		{
			transplant(head,min,min->right);
			min->right = temp->right;
			min->right->parent = min;
		}
		transplant(head,temp,min);
		min->left = temp->left;
		min->left->parent = min;
	}
	return head;
}

void transplant(bst_node *head,bst_node *u,bst_node *v)
{
	if(u->parent == NULL)
	head = v;
	else if(u == u->parent->left)
	u->parent->left = v;
	else
	u->parent->right = v;
	if(v != NULL)
	v->parent=u->parent;
}

bst_node *min_bst(bst_node *head)
{
        bst_node *temp;
        temp=head;
        while(temp->left != NULL)
                temp=temp->left;
        return temp;
}

bst_node *max_bst(bst_node *head)
{
        bst_node *temp;
        temp=head;
        while(temp->right != NULL)
                temp=temp->right;
        return temp;
}*/

