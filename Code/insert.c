#include<stdio.h>
#include"cds.h"
#include"limitsAssigned.h"
#include<malloc.h>
#include<string.h>
#include"stack.h"
#include"cds_errorcodes.h"
#include"cds_successcodes.h"
int insertRecord(char * com1,struct stack * s)
{
	FILE * fp;	
	extern int count,data_offset;	
	int i,value;
	char * result=NULL,**values,*_lastColumn=NULL;
	struct bst_node * search_result;	
	values=(char**)malloc(sizeof(char*)*cdsdetail.NoOfColumns);		
	result = strtok( com1, "," );
	values[0]=(char*)malloc(sizeof(char)*strlen(result));
	strcpy(values[0],result);
	if(count==0)
	{		
		cdsdetail.rootNode=NULL;
	}
	if((search_result=search_bst(cdsdetail.rootNode,values[0]))!=NULL )
	{			
		printf("%s\n",ERR_CDS_INSERT_DATASTORE_02);	
		return 0;
	}
	cdsdetail.rootNode=insert_into_bst(cdsdetail.rootNode,result,s);
	i=1;
	while( result != NULL&& i<cdsdetail.NoOfColumns ) 
	{
				
		result = strtok( NULL, "," );
		values[i]=(char*)malloc(sizeof(char)*strlen(result));
		strcpy(values[i],result);		
		i++;  
	}
	if(i!=cdsdetail.NoOfColumns)
	{
				
		printf("%s\n",ERR_CDS_INSERT_DATASTORE_01);
		return 0;
	}
	
	for(i=0;i<cdsdetail.NoOfColumns;i++)
	{
		
		if(i==cdsdetail.NoOfColumns-1)
		{
			
			fp=fopen(cdsdetail.datafiles[i],"r+b");	
			
			fseek(fp,cdsdetail.filedetails[i].size*(data_offset-1),1);
			_lastColumn=strtok(values[i],"\n");
			fwrite(_lastColumn,cdsdetail.filedetails[i].size,1,fp);
			fclose(fp);
		}	
		else
		{
					
			fp=fopen(cdsdetail.datafiles[i],"r+b");
			
			fseek(fp,cdsdetail.filedetails[i].size*(data_offset-1),1);
			fwrite(values[i],cdsdetail.filedetails[i].size,1,fp);
			fclose(fp);
		}
	}
	printf("%s\n",SUCCESS_CDS_INSERT_DATASTORE_00);
	/*for(i=0;i<cdsdetail.NoOfColumns;i++)
	{
		printf("inside free\n");		
		free(values[i]);
	}
	free(values);*/
	
}

