#include "unp.h"

void sig_chld(int signo) 
{
	pid_t pid;
	int stat;

	pid = wait(&wait);
	printf("child %d terminated\n", pid);
	return;
}