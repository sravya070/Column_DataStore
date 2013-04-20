#include<stdio.h>
#include"stack.h"
#include<malloc.h>
#include"limitsAssigned.h"
int push(int offset,struct stack * s)
{
	if(s->top==MAXSIZE)
	{
		printf("stack full\n");
		return 0;
	}
	s->stack_item[(s->top)++]=offset;
	return 1;
}

int pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty\n");
		return -1;
	}
	else return s->stack_item[--(s->top)];
}

/*int SerializeStack(struct stack *s,FILE * fp)
{
	for(i=0;i<s->top;i++)
	{
		fprintf(fp,"%d\n",s->stack_item[i]);
	}
	if(ftell(fp)!=0)
	{
		printf("stack is not written into the file\n");
		return 0;
	}
	printf("stack is successfully written into the file\n");
	return 1;
}*/


/*int LoadStackFromFile(FILE *fp,struct stack *s)
{
	if(ftell(fp)==0)
	{
		printf("stack file is empty\n");
		return 0;
	}
	while(1)
	{
		if(fgetc(fp)==EOF)return;
		else fseek(fp,-1,1);
		fscanf(fp,"%d",&offset);
		s->push(offset);
	}
	return 1;
}
		
}*/


