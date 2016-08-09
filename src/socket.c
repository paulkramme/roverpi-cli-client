#include<stdio.h>

int test(void)
{
	puts("Just a test function");
	return 0;
}

int socket(void)
{
	int client_socket;
	char sendline[256];
	int input = 0;
	struct sockaddr_in servaddr;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	//bzero(&servaddr,sizeof servaddr);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(22000);
	inet_pton(AF_INET, "192.168.247.15", &(servaddr.sin_addr));
	connect(client_socket, (struct sockaddr *) &servaddr, sizeof(servaddr));
	while(1)
	{
		bzero( sendline, 256);
		//fgets(sendline,2,stdin); /*stdin = 0 , for standard input */
		input = getch();
		sendline[0] = input;
		write(client_socket, sendline, strlen(sendline)+1);
	}
	/*return 0;*/
}
