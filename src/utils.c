#include "utils.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#define NUM 100

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char* token = NULL;
	char command_2nd[NUM];
	char str[] = " \t\n";
	int i = 0;

	strcpy(command_2nd, command);
	
	token = strtok(command_2nd, str);
	*argv = (char**)malloc(sizeof(char*)*NUM);

	while(token != NULL)
	{
		(*argv)[i] = (char*)malloc(sizeof(char)*NUM);
		strcpy((*argv)[i],token);
		token = strtok(NULL,str);
		i ++;
	}
	*argc = i;


}
