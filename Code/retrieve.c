#include<stdio.h>
#include"cds.h"
void RetrieveFromFile(FILE * fp,int offset,int size);
void Retrieve_data(char * com1)
{
	char * temp1=NULL,*temp2=NULL;
	FILE * fp;
	int offset,size,i;
	bst_node *search_result,*search_head;	
	temp1=strtok(com1,"=");
	temp2=strtok(NULL,"\n");	
	search_result=search_bst(cdsdetail.rootNode,temp2);
	
	if(search_result==NULL)
	{
		return;
	}
	else
	{
		offset=(search_result->offset)-1;
		printf("%d\t%s\n",offset,search_result->data);
		for(i=0;i<cdsdetail.NoOfColumns;i++)
		{
			fp=fopen(cdsdetail.datafiles[i],"rb");
			size=cdsdetail.filedetails[i].size;
			RetrieveFromFile(fp,offset,size);
			fclose(fp);
		}
	}
}

void RetrieveFromFile(FILE * fp,int offset,int size)
{
	char buffer[50];
	while(1)
	{
		if(fread(buffer,size,1,fp)!=0)
		{
			//printf("%s\n",buffer);
		}
		else break;
	}
}
