#include<stdio.h>
#include"cds.h"
#include"stack.h"
#include"cds_errorcodes.h"
#include"cds_successcodes.h"

int LoadFromFile(struct stack * s)
{
	FILE * fp,*loadKey;
	extern int count,CDS_LOADED;
	int n;
	char buffer[cdsdetail.filedetails[0].size];
	fp=fopen(cdsdetail.datafiles[0],"rb");
	/*if(loadKey==NULL)
	{
		printf("%s\n",ERR_CDS_CREATE_DATASTORE_02 );
		return;
	}*/
	//else
	//{
		
	if(fp==NULL)
	{
		printf("%s\n",ERR_CDS_CREATE_DATASTORE_02 );
		return;
	}
	if(count==0)

	{
		cdsdetail.rootNode=NULL;
	}
	while(1)
	{
		if((n=fread(buffer,cdsdetail.filedetails[0].size,1,fp))!=0)
		{
		cdsdetail.rootNode=insert_into_bst(cdsdetail.rootNode,buffer,s);
		//printf("%s\n",cdsdetail.rootNode->data);
		}
		else 
		{		
			break;	
		}
	}
	
	fclose(fp);
	CDS_LOADED=1;	
	return 1;
}
