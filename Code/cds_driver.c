#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"cds.h"
#include"stack.h"
#include"cds_errorcodes.h"
#include"cds_successcodes.h"
int count;
int data_offset;
int deleted_offset;
int CDS_LOADED;
void process_command(char *,char *,char*,struct stack *);
void main(int argc, char * argv[])
{
	FILE * fp;
	char  buffer[100],*command,*com2,*com1,*result=NULL,**coms,*dummy=NULL;
	int j;
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->top=0;
	coms=(char**)malloc(sizeof(char*)*2);
	fp=fopen(argv[1],"r");
	while(1)
	{
		if(fgetc(fp)==EOF)break;
		else fseek(fp,-1,1);		
		fgets(buffer,sizeof(buffer),fp);				
		command = strtok( buffer," ");
		if(strcmp(command,"create\n")==0)
		{
			printf("%s\n",ERR_CDS_CREATE_DATASTORE_00 );
			
		}
		else if(strcmp(command,"load\n")==0)
		{
			printf("%s\n",ERR_CDS_LOAD_DATASTORE_00 );
		}
		else if(strcmp(command,"load")==0)
		{
			j=0;			
			while(j!=2)
			{
				result=strtok(NULL," ");
				if(result==NULL)
				{
					printf("%s\n",ERR_CDS_LOAD_DATASTORE_00);
					break;
				}
				else
				{
					
					
					coms[j]=(char*)malloc(sizeof(char)*strlen(result));
					strcpy(coms[j],result);
					j++;
					
				}
			}
			process_command(command,coms[0],coms[1],s);					
					
		}			
		else if(strcmp(command,"insert\n")==0)
		{
			printf("%s\n",ERR_CDS_INSERT_DATASTORE_00 );
			
		}
		else if(strcmp(command,"insert")==0)
		{
			
			coms[0]=strtok(NULL," ");
			coms[1]=NULL;
			process_command(command,coms[0],coms[1],s);
		}
		else if(strcmp(command,"retrieve\n")==0)
		{
			printf("%s\n",ERR_CDS_RETRIEVE_DATASTORE_00 );
			
		}
		else if(strcmp(command,"update\n")==0)
		{
			printf("%s\n",ERR_CDS_CREATE_DATASTORE_00 );
			
		}
		else if(strcmp(command,"delete\n")==0)
		{
			printf("%s\n",ERR_CDS_CREATE_DATASTORE_00 );
			
		}
		else if(strcmp(command,"delete")==0)
		{
			result=strtok(NULL," ");
			coms[0]=(char*)malloc(sizeof(char)*strlen(result));
			strcpy(coms[0],result);
			coms[1]=NULL;
			process_command(command,coms[0],coms[1],s);
		}
		else if(strcmp(command,"update")==0)
		{
			j=0;			
			while(j!=2)
			{
								
				coms[j]=strtok(NULL," ");
				if(coms[j]==NULL)
				{
					printf("%s\n",ERR_CDS_UPDATE_DATASTORE_00);
					break;
				}
				else
				{
					if(strcmp(coms[j],"where")==0);
					else
					{
						
						j++;
						
					}
				}
						
			}	
			process_command(command,coms[0],coms[1],s);			
			
		}
		else if(strcmp(command,"retrieve")==0)
		{
			j=0;			
			while(j!=2)
			{
				coms[j]=strtok(NULL," ");
				if(coms[j]==NULL)
				{
					printf("%s\n",ERR_CDS_RETRIEVE_DATASTORE_00);
					break;
				}
				else
				{
					if(strcmp(coms[j],"where")==0);
					else
					{
						
						
						j++;
					}
				}
						
			}
			process_command(command,coms[0],coms[1],s);		
		}		
		else if(strcmp(command,"create")==0)

		{
			j=0;			
			while(j!=2)
			{
				result=strtok(NULL," ");
				if(result==NULL)
				{
					printf("%s\n",ERR_CDS_RETRIEVE_DATASTORE_00);
					break;
				}
				else
				{
					
					
					coms[j]=(char*)malloc(sizeof(char)*strlen(result));
					strcpy(coms[j],result);
					j++;
					
				}
						
			}
			process_command(command,coms[0],coms[1],s);					
			
		}
		
			
		

	}	
}

void process_command(char * command,char * com1, char * com2,struct stack * s)
{
		
	int result,*temp=NULL;
	
	if(strcmp(command,"create")==0)
	{	
		result=createDatastore(com2,s);
		if(result==1)printf("%s\n",SUCCESS_CDS_CREATE_DATASTORE_00);
			
	}
	else if(strcmp(command,"load")==0)
	{
		LoadFromFile(s);
		if(CDS_LOADED==1)
		{
			printf("%s\n",SUCCESS_CDS_LOAD_DATASTORE_00);
		}
	}

	else if(strcmp(command,"insert")==0) 
	{
		if(CDS_LOADED==1)
		{		
			if(com1!=NULL&&com2==NULL)
			{
				result=insertRecord(com1,s);
			}
			else
			{
				printf("more arguments\n");
			
			}
		}
		else
		{
			printf("%s\n",ERR_CDS_LOAD_DATASTORE_01);
		}
	}
	else if(strcmp(command,"delete")==0)
	{
		if(CDS_LOADED==1)
		{
			
			if(com1!=NULL&&com2==NULL)
			{
								
			temp=strtok(com1,"=");
			temp=strtok(NULL,"=");				
			result=deleteByKey(temp,s);
			}
			else
				printf("more arguments\n");
		}
		else
		{
			printf("%s\n",ERR_CDS_LOAD_DATASTORE_01);
		}
	}
		
		else if(strcmp(command,"update")==0)
		{
			if(CDS_LOADED==1)
			{

			if(com1!=NULL && com2!=NULL)
			{	
				
				update(com1,com2);
			}
			else
				printf("insufficient arguments\n");
			}
			else 
				printf("%s\n",ERR_CDS_LOAD_DATASTORE_01);
		
		}
		else if(strcmp(command,"retrieve")==0)
		{
			if(CDS_LOADED==1)
						
			retrieve(com1,com2);
			else
				printf("%s\n",ERR_CDS_LOAD_DATASTORE_01);
		}
		
}

