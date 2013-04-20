#include"limitsAssigned.h"
#include "bst.h"
struct file
{
	FILE * filepointer;
	int dataType;
	int size;
};
struct cds_detail
{
	char * dataStoreName;	
	struct file filedetails[MAX_COL];
	int cds_state;
	int NoOfColumns;
	char  datafiles[100][25];
	struct bst_node *rootNode;
	
}cdsdetail;

//cdsdetail.rootNode=NULL;
//node *rootNode=(node *)malloc(sizeof(node));
	
