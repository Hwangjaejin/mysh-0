#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
	if (!validate_cd_argv(argc, argv))
    		return -1;
	
	
	chdir(argv[1]);
	return 0;
}

int do_pwd(int argc, char** argv) {
	if (!validate_pwd_argv(argc, argv))
    		return -1;

	char buf[1024];
	getcwd(buf,1024);
	printf("%s\n",buf);	

  	return 0;
}

int validate_cd_argv(int argc, char** argv) {
	if(argc == 2 && !(strcmp(argv[0], "cd")))
		return 1;
	else
		return 0;
}

int validate_pwd_argv(int argc, char** argv) {
	if(argc == 1 && !(strcmp(argv[0], "pwd")))  
  		return 1;
	else
		return 0;
}
