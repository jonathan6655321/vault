#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "initVault.h"

int initVault (int argc, char **argv)
{
	printf("hey i am in initVault.c\n\n");

	if(argc != 4)
	{
		printf("Error: invalid number of arguments\n\n");
	}

	char* repoName = argv[1];
	int vaultFileDescriptor = open( repoName , O_WRONLY | O_CREAT, 0777);
	if(vaultFileDescriptor == -1)
	{
		printf("Error: couldn't create or open the vault file.");
		return -1;
	}

	write(int fd, const void *buf, size_t count);


}
