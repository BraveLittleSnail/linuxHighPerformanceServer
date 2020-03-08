#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//sigcld�źŴ�����
void sigcld_cb(int signo)
{
	int pid;
	int status;

	pid = waitpid(-1,&status,0);
	//����˳��ӽ���ID���˳�����
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

	//ѭ�������ӽ���
	for (int i = 0; i < 5; i++)
	{
		//����һ���ӽ���
		pid = fork();
		//�������ʧ�ܣ����Ƴ�
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