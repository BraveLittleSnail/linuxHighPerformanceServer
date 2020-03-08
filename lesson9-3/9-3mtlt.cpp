#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>


#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 10
using  namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 2)
	{
		printf("用法：%s ip_addr port\n", basename(argv[0]));
		return 1;
	}

	const char* ip = argv[1];
	int port = atoi(argv[2]);

	sockaddr_in address;
	bzero(&address, sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	//创建监听fd
	int listenfd = socket(PF_INET, SOCK_STREAM,0);
	assert(listenfd>=0);
	
	int ret = 0;

	ret = bind(listenfd, (sockaddr*)&address, sizeof(address));
	assert(ret != -1);
	
	ret = listen(listenfd,5);
	assert(ret != -1);

	int  pollfd = epoll_create(5);






	return 1;

}