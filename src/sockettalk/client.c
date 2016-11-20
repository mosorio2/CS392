#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include "../../include/my.h"
#define buff 1024

int main(int argc, char** argv)
{
	int the_socket;
	int port;
	int pid;
	int name;
	int n;	
	char ip[100];
	char server_msg[buff];
	char msg[buff];
	char* nickname = (char*)malloc(25*sizeof(char));
	char *message = (char*)malloc(256*sizeof(char));
	struct in_addr **addr_list;
	struct sockaddr_in server_add;
	struct hostent* server;

	if(argc < 3)
	{
		my_str("Usage: ./client [host] [port]\n");
		exit(0);
	}

	my_str("Nickname: ");
	name = read(0, nickname, 24);
	nickname[name - 1] = '\0';
	port = my_atoi(argv[2]);
	the_socket = socket(AF_INET, SOCK_STREAM, 0);

	if(the_socket < 0)
	{
		my_str("Error: Cannot open socket\n");
	}

	server = gethostbyname(argv[1]);

	if (server == NULL)
	{
		my_str("Error: invalid host. Please try again.\n");
		exit(0);
	}

   	 addr_list = (struct in_addr **) server->h_addr_list;

	 for(n = 0; addr_list[n] != NULL; n++) 
	 {
		my_strcpy(ip , inet_ntoa(*addr_list[n]) );
	 }

	 server_add.sin_addr.s_addr = inet_addr(ip);
	 server_add.sin_family = AF_INET;
	 server_add.sin_port = htons(port);

	if(connect(the_socket, (struct sockaddr*) &server_add, sizeof(server_add)) < 0)
	{
		my_str("Error: Unable to connect. Please try again. ");
		my_str(argv[1]);
		my_char('\n');
		exit(0);
	}

	if((pid = fork()) < 0)
	{
			my_str("fork error\n");
			exit(1);
	}

	else if (pid == 0)
	{
		while(1)
		{
			for(n = 0; n < buff; n++)
			{
				msg[n] = '\0';
			}

		    	name = read(0, msg, buff-1);
		    	msg[name] = '\0';

			if (my_strncmp(msg, "/exit", 5) == 0)
			{
				my_str("Thank you for using sockettalk.\nExiting\n");
				kill(pid, SIGINT);
   				close(the_socket);
				return 0;
			}

			else if (my_strncmp(msg, "/nick", 5) == 0)
			{
				if (my_strncmp(msg, "/nick ", 6)==0)
				{
					my_str("Changing nickname to: ");
					my_strncpy(nickname, &msg[6], my_strlen(&msg[6]) - 1);
					my_str(nickname);
					my_str("\n");
				}
				else
				{
					my_str("Usage: ./nick [nickname]\n");
				}
			}

			else if (my_strncmp(msg, "/me", 3) == 0)
			{
				if (my_strncmp(msg, "/me ", 4) == 0)
				{
					message = my_strconcat(nickname, &msg[3]);
					send(the_socket, message, my_strlen(message + 1), 0);
				}
				else
				{
					my_str("Usage: ./me [nickname] [message]\n");
				}
			}

			else if (my_strncmp(msg, "/", 1) == 0)
			{
				message = "Error: Command not recognized";
				send(the_socket, message, my_strlen(message), 0);
				my_str("\n");
			}

			else
			{
				message = my_strconcat(nickname, ": ");
				message = my_strconcat(message, msg);

				if(send(the_socket , message, my_strlen(message + 1), 0) < 0)
				{
				    my_str("Error: Send failed. Please try again.\n");
				    exit(0);
				}
			}
		}
	}

	else
	{
		while(1)
		{
			for(n = 0; n < buff; n++)
			{
				server_msg[n] = '\0';
			}

			if(recv(the_socket , server_msg , sizeof(server_msg), 0) < 0)
			{
			    my_str("Error: Receiving error\n");
			    exit(0);
			}

	       		my_str(server_msg);
		}
	}

	kill(pid, SIGINT);
   	close(the_socket);
	return 0;
}
