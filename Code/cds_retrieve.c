#include<stdio.h>
#include"cds.h"
#include"limitsAssigned.h"
#include<malloc.h>
#include<string.h>
#include"cds_errorcodes.h"
#include"cds_successcodes.h"
void retrieveFromFile(char * com1,int offset,FILE * fp,char * a);
int retrieve(char *com1,char *com2)
{
	FILE *fp;
	char buffer[200];
	int k=0,j=0,offset;
	extern int count;	
	char *temp,*temp1,*temp3;
	bst_node *search;
	temp=strtok(com2,"=");
	temp1=strtok(NULL,"\n");
	if((search=search_bst(cdsdetail.rootNode,temp1))==NULL)
	{
		printf("%s\n",ERR_CDS_RETRIEVE_DATASTORE_02);
		return 0;		
	}	
	offset=(search->offset)-1;
	//if(search->flag==1)return 0;
	strcat(com1,",");
	temp3=strtok(com1,",");
	fp=fopen(com1,"rb");
	strcpy(buffer,SUCCESS_CDS_RETRIEVE_DATASTORE_00);	
	retrieveFromFile(com1,offset,fp,buffer);
	fclose(fp);
	while(com1!=NULL)
	{
		if((com1=strtok(NULL,","))!=NULL)
		{		
			fp=fopen(com1,"rb");	
			strcat(buffer,",");		
			retrieveFromFile(com1,offset,fp,buffer);
			fclose(fp);
			
		}
		else
			break;
		
	}
	printf("%s\n",buffer);	
	return 1;
}

void retrieveFromFile(char * com1,int offset,FILE * fp,char * result)
{
	int i,size;
	char attribute_value[25];
	for(i=0;i<cdsdetail.NoOfColumns;i++)
	{
		if(strcmp(com1,cdsdetail.datafiles[i])==0)
		{
			size=cdsdetail.filedetails[i].size;
			break;
		}
	}
	
	if(fp==NULL)
	{
		printf("%s\n",ERR_CDS_RETRIEVE_DATASTORE_01);
		return;
	}
	else
	{
		fseek(fp,size*offset,0);		
		fread(attribute_value,size,1,fp);
		strcat(result,attribute_value);
	}
	
}
