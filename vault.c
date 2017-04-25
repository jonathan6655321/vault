#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "initVault.h"
#include "listFiles.h"
#include "addFile.h"
#include "removeFile.h"
#include "fetchFile.h"
#include "defragVault.h"
#include "getVaultStatus.h"

/*
This is the main file in the project.
It gets the arguments from the user and calls the relevant functions.
*/

// supported operations by the vault
typedef enum OperationType {
	INIT_VAULT,
	LIST_FILES,
	ADD_FILE,
	REMOVE_FILE,
	FETCH_FILE,
	DEFRAG_VAULT,
	GET_VAULT_STATUS,
	INVALID_OPERATION} OperationType;

OperationType getOperationTypeFromString(char* s);
int runOperation(OperationType op, int argc, char** argv);


int main (int argc, char **argv)
{
	if(argc < 3)
	{
		printf("Error: invalid number of arguments\n\n");
		return -1;
	}
		
	OperationType op = getOperationTypeFromString(argv[2]);

	if(op == INVALID_OPERATION)
	{
		printf("Error: invalid operation argument\n\n");
		return -1;
	}
	else
	{
		runOperation(op, argc, argv);
	}
	
	return 1;
}

OperationType getOperationTypeFromString(char* s)
{
	if(strcmp(s,"init")==0)
	{
		return INIT_VAULT;
	} else if(strcmp(s,"list")==0)
	{
		return LIST_FILES;
	} else if(strcmp(s,"add")==0)
	{
		return ADD_FILE;
	} else if(strcmp(s,"rm")==0)
	{
		return REMOVE_FILE;
	} else if(strcmp(s,"fetch")==0)
	{
		return FETCH_FILE;
	} else if(strcmp(s,"defrag")==0)
	{
		return DEFRAG_VAULT;
	} else if(strcmp(s,"status")==0)
	{
		return GET_VAULT_STATUS;
	}
	else
	{
		return INVALID_OPERATION;
	}
}


int runOperation(OperationType op, int argc, char** argv)
{
	if(op == INIT_VAULT)
	{
		initVault(argc, argv);
	}else if(op == LIST_FILES)
	{
		listFiles();
	}else if(op == ADD_FILE)
	{
		addFile();
	}else if(op == REMOVE_FILE)
	{
		removeFile();
	}else if(op == FETCH_FILE)
	{
		fetchFile();
	}else if(op == DEFRAG_VAULT)
	{
		defragVault();
	}else if(op == GET_VAULT_STATUS)
	{
		getVaultStatus();
	}else if(op == INVALID_OPERATION)
	{
		return -1;
	}

	return 1;
}
