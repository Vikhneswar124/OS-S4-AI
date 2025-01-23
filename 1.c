#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
	{
	int status,pid,child_pid;
	pid=fork();
	if(pid==-1)
		{
		printf("Child process creation failed!");
		exit(0);
		}
		else if(pid==0)
		{
		printf("Inside Child Process with process ID: %d\n",getpid());
		execlp("/bin/date","date",NULL);
		exit(0);
		}
		else
		{
			child_pid=wait(&status);
			printf("\n Inside parent Process with process ID: %d\n",getpid());
			printf("Child process created successfully\n");
		}
	}	
