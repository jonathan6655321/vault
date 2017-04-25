#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct RepoMetaData 
{
	ssize_t repositoryTotalSize;
	time_t creationTimeStamp;
	time_t lastModificationTimeStamp;
	short numFilesInVault;
}repoMetaData;

typedef struct FileAllocationTableEntry
{
	char* fileName;
	ssize_t fileSize;
	// st_mode fileProtection;
	time_t insertionDateStamp;
	off_t dataBlockOffset1;
	ssize_t dataBlockSize1;
	off_t dataBlockOffset2;
	ssize_t dataBlockSize2;
	off_t dataBlockOffset3;
	ssize_t dataBlockSize3;
}FileAllocationTableEntry;