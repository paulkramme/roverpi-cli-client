/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h> 
#include"getch.h"

int main(void)
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
}

