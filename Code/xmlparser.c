#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct attribute{
char attr_name[100];
char attr_type[100];
struct attribute * next;
};
struct node{
char table_name[100];
struct attribute a;
struct node * next;
};

void main(int argc, char ** argv){
	FILE *fp,*fp1,*fp2;
	int i;
	struct node * n;
	struct attribute * a;
	char str[100],c,new_str[100],dbname[100];
	fp=fopen(argv[1],"r");
	fp2=fopen("attributes","w");
	n=(struct node *) malloc(sizeof(struct node));
	fseek(fp,1,1);
	while((c=fgetc(fp))!='<');
	
	while((c=fgetc(fp))!='>');
	i=0;		
	while((c=fgetc(fp))!='<'){dbname[i]=c;i++;}
	dbname[i]='\0';
	fprintf(fp2,"%s\n",dbname);
		
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
			strcpy(n->table_name,new_str);
			printf("%s\n",n->table_name);
			fprintf(fp2,"%s\n",n->table_name);
		}
		else if(strcmp(str,"attrname")==0)
		{
						
			a=(struct attribute *)malloc(sizeof(struct attribute));
			i=0;
			while((c=fgetc(fp))!='<'){new_str[i]=c;i++;}
			new_str[i]='\0';
			strcpy(n->a.attr_name,new_str);
			fp1=fopen(n->a.attr_name,"a");
			fclose(fp1);
			fprintf(fp2,"%s:",n->a.attr_name);
			i=0;
			while((c=fgetc(fp))!='<');
			while((c=fgetc(fp))!='>'){str[i]=c;i++;}
			str[i]='\0';
			//printf("%s\n",str);
			if(strcmp(str,"attrtype")==0)
			{
				i=0;
				while((c=fgetc(fp))!='<'){new_str[i]=c;i++;}
				new_str[i]='\0';
				strcpy(n->a.attr_type,new_str);
				fprintf(fp2,"%s\n",n->a.attr_type);
				printf("%s\n",n->a.attr_type);
			}
			a=a->next;		
		}	
		
	}
			
	
}
		
fclose(fp2);
fclose(fp);
}			
