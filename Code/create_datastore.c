#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"cds.h"
#include"limitsAssigned.h"
#include"stack.h"
#include"cds_successcodes.h"
int createDatastore(char * filename,struct stack * s){	
	FILE *fp,*fp1,*fp2,*storePrimary;
	int i,x=0,count=0,p,output,size;
	char str[100],c,new_str[100],dbname[100],*file_name,sample[50];
	file_name=(char*)malloc(sizeof(char)*strlen(filename));
	strncpy(file_name,filename,strlen(filename)-1);
	fp=fopen(file_name,"r");
	fseek(fp,1,1);
	while((c=fgetc(fp))!='<');
	while((c=fgetc(fp))!='>');
	i=0;		
	while((c=fgetc(fp))!='<'){dbname[i]=c;i++;}
	dbname[i]='\0';
	cdsdetail.dataStoreName=(char*)malloc(sizeof(char)*strlen(dbname));
	strcpy(cdsdetail.dataStoreName,dbname);
	p=0;	
	while((c=fgetc(fp))!=EOF){	
	if(c=='<')
	{
		i=0;	
		while((c=fgetc(fp))!='>'){str[i]=c; i++;}
		str[i]='\0';
		if(strcmp(str,"table_name")==0)
		{
			i=0;			
			while((c=fgetc(fp))!='<'){new_str[i]=c; i++;}			
			new_str[i]='\0';			

		}
		else if(strcmp(str,"attrname")==0)
		{					
			i=0;
			while((c=fgetc(fp))!='<'){new_str[i]=c;i++;}
			new_str[i]='\0';
			strcpy(cdsdetail.datafiles[p],new_str);
			fp1=fopen(cdsdetail.datafiles[p],"a+b");
			fclose(fp1);
			count++;
			i=0;
			while((c=fgetc(fp))!='<');
			while((c=fgetc(fp))!='>'){str[i]=c;i++;}
			str[i]='\0';
			if(strcmp(str,"attrtype")==0)
			{
				i=0;
				while((c=fgetc(fp))!='<'){new_str[i]=c;i++;}
				new_str[i]='\0';
				if(strcmp(new_str,"int")==0)
				{				
				cdsdetail.filedetails[p].dataType=INT;
				}
				else 
				cdsdetail.filedetails[p].dataType=STRING;
			}
			i=0;
			while((c=fgetc(fp))!='<');
			while((c=fgetc(fp))!='>'){str[i]=c;i++;}
			str[i]='\0';
			if(strcmp(str,"size")==0)
			{
								
				i=0;
				while((c=fgetc(fp))!='<'){new_str[i]=c;i++;}
				new_str[i]='\0';
				size=atoi(new_str);
				cdsdetail.filedetails[p].size=size;
				
				
			}	
			p++;		
		}	
		
	}
			
	
}

cdsdetail.NoOfColumns=p;
output=LoadFromFile(s);		
fclose(fp);
return 1;
}			
