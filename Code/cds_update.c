#include<stdio.h>
#include"cds.h"
#include"limitsAssigned.h"
#include<malloc.h>
#include<string.h>
#include"cds_errorcodes.h"
#include"cds_successcodes.h"
//#include"bst.h"
void stringsplit(char *strsplit,int offset);
void updateFile(char * column, char * value,int offset);
void update(char *com1,char *com2)
{
	char *temp1=NULL,*temp2,*temp3=NULL,*temp4=NULL,**values={NULL},*temp5=NULL;
	int i=0,size,j,offset;
	char *split1,*split2;
	char temp_data[10];
	bst_node *search_result,*search_head;	
	temp1=strtok(com2,"=");
	temp2=strtok(NULL,"\n");	
	strcpy(temp_data,temp2);
	search_result=search_bst(cdsdetail.rootNode,temp_data);
	if(search_result==NULL)
	{
		printf("%s\n",ERR_CDS_UPDATE_DATASTORE_02);
		return;
	}
	else
	{
	if(search_result->flag==1)return 0;
	offset=search_result->offset;
	temp3 = strtok( com1, "," );
	temp4=(char*)malloc(sizeof(char)*strlen(temp3));
	strcpy(temp4,temp3);
	temp3 = strtok( NULL, "," );
	if(temp3!=NULL)
	{
		temp5=(char*)malloc(sizeof(char)*strlen(temp3));
		strcpy(temp5,temp3);
	}
	stringsplit(temp4,offset);
	//free(temp4);
	while( temp3 != NULL) 
	{
			
			
		temp3= strtok( temp5, "," );
		free(temp5);
		if(temp3!=NULL)
		{		
			temp4=(char*)malloc(sizeof(char)*strlen(temp3));
			strcpy(temp4,temp3);
		}
		temp3=strtok(NULL,",");
		stringsplit(temp4,offset);
		//free(temp4);
		if(temp3!=NULL)
		{	
			temp5=(char*)malloc(sizeof(char)*strlen(temp3));
			strcpy(temp5,temp3);	
		}	
		
		
	}
	//if(temp5!=NULL)//free(temp5);
	
	}
}

void stringsplit(char *strsplit,int offset)
{
		
	char *split1,*split2,buffer[50];
	split1=strtok(strsplit,"=");
	split2=strtok(NULL,"");
	updateFile(split1,split2,offset);
	
	
} 
void updateFile(char * column, char * value,int offset)
{
	FILE * fp;
	int i,size;
	char buffer[25];
	fp=fopen(column,"rb+");
	if(fp==NULL)
	{
		printf("%s\n",ERR_CDS_UPDATE_DATASTORE_01);
		return;
	}	
	for(i=0;i<cdsdetail.NoOfColumns;i++)
	{	
		if(strcmp(column,cdsdetail.datafiles[i])==0)
		{
			fseek(fp,(offset-1)*cdsdetail.filedetails[i].size,0);			
			fwrite(value,cdsdetail.filedetails[i].size,1,fp);
		}
	}
	for(i=0;i<cdsdetail.NoOfColumns;i++)
	{
		
		
		if(strcmp(column,cdsdetail.datafiles[i])==0)
		{
			size=cdsdetail.filedetails[i].size;
			break;

		}
	}
	rewind(fp);
	printf("%s\n",SUCCESS_CDS_UPDATE_DATASTORE_00);
	/*while(1)
	{
		if(fread(buffer,size,1,fp)!=0)
		{
			printf("%s\n",buffer);
		}
		else
			break;
	}*/	
	fclose(fp);
	
	
}

