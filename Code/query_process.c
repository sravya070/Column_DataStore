#include<stdio.h>
#include<string.h>
#include<malloc.h>
void main(int argc, char ** argv)
{
	FILE * fp,*fp1,*fp2;
	char tname[100],dbname[100],c,*d_name,*t_name,c1,str[100],delims[] = ",",*result = NULL,**attributes,p,**types,str1[100],**values,*result1 = NULL,new_str[100],*values1;
	int i,len,count,count1,j,k;
	printf("the attribute file is %s\n",argv[1]);
	printf("the query file is %s\n",argv[2]);
	fp=fopen(argv[1],"r");
	fp1=fopen(argv[2],"r");
	while((c=fgetc(fp1))!=' ');
	i=0;	
	while((c=fgetc(fp1))!='\n'){dbname[i]=c;i++;}
	dbname[i]='\0';
	d_name=(char *)malloc(sizeof(char)*strlen(dbname));
	strcpy(d_name,dbname);
	printf("%s\n",d_name);	
	while((c=fgetc(fp1))!=' ');
	while((c=fgetc(fp1))!=' ');
	i=0;
	while((c=fgetc(fp1))!=' '){tname[i]=c;i++;}
	tname[i]='\0';
	t_name=(char *)malloc(sizeof(char)*strlen(tname));
	strcpy(t_name,tname);
	printf("%s\n",t_name);
	i=0;
	while((c1=fgetc(fp))!='\n'){dbname[i]=c1;i++;}
	dbname[i]='\0';
	i=0;
	while((c1=fgetc(fp))!='\n'){tname[i]=c1;i++;}
	tname[i]='\0';
	printf("%s\t%s\n",dbname,tname);
	if(strcmp(dbname,d_name)!=0)
	{
		printf("database names do not match\n");
	}
	else if(strcmp(tname,t_name)!=0)
	{
		printf("table names do not match\n");
	}
	else
	{
		count=0;
		count1=0;
		fseek(fp1,0,0);
		while((c=fgetc(fp1))!='\n');
		while((c=fgetc(fp1))!='(');
		i=0;
		while((c=fgetc(fp1))!=')'){str[i]=c;i++;}
		str[i]='\0';
		printf("%s\n",str);
		strcpy(new_str,str);
		result = strtok( str, delims );
		while( result != NULL ) 
		{
    			printf( "%s\n", result );
			count1++;
    			result = strtok( NULL, delims );
		}
		values=(char**)malloc(sizeof(char*)*count1);
		k=0;
		result1 = strtok( new_str, delims );		
		while( result1!=NULL) 
		{
    			//printf( "%s\n", result );
			values[k]=(char*)malloc(sizeof(char)*strlen(result1));
			strcpy(values[k],result1);
						
			printf("%s****\n",values[k]);
			printf("%c*##\n",values[k][0]);
			
			k++;
    			result1 = strtok( NULL, delims );
		}
		
		while((p=fgetc(fp))!=EOF)
		{
			while((p=fgetc(fp))!='\n');
			count++;
		}
		
		printf("%d\t%d\n",count,count1);
		if(count==count1)
		{
			fseek(fp,0,0);
			while((p=fgetc(fp))!='\n');
			while((p=fgetc(fp))!='\n');
			attributes=(char**)malloc(sizeof(char*)*count);
			types=(char**)malloc(sizeof(char*)*count);
			for(j=0;j<count;j++)
			{
				i=0;
				while((p=fgetc(fp))!=':'){str[i]=p;i++;}
				str[i]='\0';
				attributes[j]=(char*)malloc(sizeof(char)*strlen(str));
				strcpy(attributes[j],str);
				i=0;
				p=fgetc(fp);
							
				while(p!='\n'){if(p==EOF)break;str[i]=p;i++;p=fgetc(fp);}
				str[i]='\0';
				types[j]=(char*)malloc(sizeof(char)*strlen(str));
				strcpy(types[j],str);
				printf("%s\t%s\n",attributes[j],types[j]);
				
			}
			for(j=0;j<count;j++)
			{
				if((values[j][0]=='\'')&&(strcmp(types[j],"string")==0))
				{
					
					result = strtok(values[j], "\'" );
					while( result != NULL ) 
					{
    						printf("%s&&&&\n",result);
						fp2=fopen(attributes[j],"a"); 
						fprintf(fp2,"%s\n",result);		
						fclose(fp2);    						
						result = strtok( NULL, "\'");
						
					}
										
					
				}
				else if(values[j][0]!='\'' && strcmp(types[j],"int")==0)
				{
					fp2=fopen(attributes[j],"a");	
					fprintf(fp2,"%s\n",values[j]);
					fclose(fp2);
				}
				else {printf("types do not match\n");}
			}
		}		
					
	}	



}
	
	
