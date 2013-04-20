#include<stdio.h>
void main()
{
	FILE * fp;
	char buffer[25];
	fp=fopen("RollNo","rb");
	while(1)
	{
		if(fgetc(fp)==EOF)break;
		else
			fseek(fp,-1,1);
		fread(buffer,15,1,fp);
		printf("%s\n",buffer);
	}
}
