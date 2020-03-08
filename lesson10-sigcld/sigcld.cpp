#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//sigcld信号处理函数
void sigcld_cb(int signo)
{
	int pid;
	int status;

	pid = waitpid(-1,&status,0);
	//输出退出子进程ID和退出代码
	printf("child process %d exit with status %d \n",pid,status);
	

}

int main()
{
	int i, pid;
	if (signal(SIGCLD, sigcld_cb)==SIG_ERR)
	{
		perror("signal");
		return 1;
	}

	//循环创建子进程
	for (int i = 0; i < 5; i++)
	{
		//创建一个子进程
		pid = fork();
		//如果创建失败，则推出
		if (pid == 0)
		{
			exit(0);
		}
		else
		{
			sleep(10);
		}
	}
	printf("man process");

}