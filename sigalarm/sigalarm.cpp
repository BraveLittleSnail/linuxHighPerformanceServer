#include <unistd.h>
#include <stdio.h>
#include <signal.h>

//sigalarm信号处理函数

int cnt = 0;
void sigAlarm_cb(int signo)
{
	printf("seconds: %d", cnt);
	printf("%r");
	alarm(1);
}
int main()
{
	if(signal(SIGALRM, sigAlarm_cb)== SIG_ERR)
	{
		perror("signal");
		return;
	}

	setbuf(stdout, NULL);
	alarm(1);
	while (1)
	{
		pause();
	}
}