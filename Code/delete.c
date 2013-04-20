#include<stdio.h>
#include"cds.h"
#include"stack.h"
#include"cds_errorcodes.h"
#include"cds_successcodes.h"
void delete_from_file(int);
int deleteByKey(char * key,struct stack * s)
{
	char * temp=NULL;	
	bst_node * node;	
	temp=strtok(key,"\n");	
	node=search_bst(cdsdetail.rootNode,temp);
	if(node==NULL)
	{
		printf("%s\n",ERR_CDS_DELETE_DATASTORE_01);
		return 0;
	}
	printf("%s\n",SUCCESS_CDS_DELETE_DATASTORE_00);
		
	node->flag=1;	
	push(node->offset,s);
	
	printf("inside delete ..... %d\n",s->stack_item[--(s->top)]);
	s->top++;	
	node->flag=0;
	return 1;
}
/*void delete_from_file(int offset)
{
	int i;
	char *s;
	FILE * fp;
	
	for(i=0;i<cdsdetail.NoOfColumns;i++)
	
	{
			
		fp=fopen(cdsdetail.datafiles[i],"rb+");
		fseek(fp,(offset-1)*cdsdetail.filedetails[i].size,0);	
		fwrite(" ",1,cdsdetail.filedetails[i].size,fp);		
		fclose(fp);
	}
	
}*/
