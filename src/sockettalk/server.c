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
	int maximum;
	int new_actor;
	int the_socket;
	int client;
	int port;
	int offset = 0;
	int n;
	int m;
	int i;
	int ok;
	char buffer[buff];
	char *message = (char*)malloc(256*sizeof(char));
	struct sockaddr_in client_add;
	struct sockaddr_in server_add;
	fd_set prime;
	fd_set reader;
	FD_ZERO(&prime);
   	FD_ZERO(&reader);

	if(argc < 2)
	{
		my_str("Usage: ./server [portnumber]\n");
		exit(0);
	}

	the_socket = socket(AF_INET, SOCK_STREAM, 0);

	if(the_socket < 0)
	{
		my_str("Error: Unable to create socket\n");
		exit(0);
	}

	port = my_atoi(argv[1]);

	if(port < 1 || port > 65535)
	{
		my_str("Error: Invalid port number. Please try again.\n");
		exit(0);
	}

	server_add.sin_family = AF_INET;
	server_add.sin_port = htons(port);
	server_add.sin_addr.s_addr = INADDR_ANY;

	for(m = 0; m < 8; m++)
	    (server_add.sin_zero)[m] = '\0';

	if(bind(the_socket, (struct sockaddr*) &server_add, sizeof(server_add)) < 0)
	{
		my_str("Error: bind error\n");
		exit(0);
	}

	if(listen(the_socket, 10) < 0)
	{
		my_str("Error: listen error");
		exit(0);
	}

	my_str("Server running. Welcome.\n");
	FD_SET(the_socket, &prime);
	maximum = the_socket;

	while(1)
	{
		reader = prime;

		for(m = 0; m < buff; m++)
		{
		    buffer[m] = '\0';
		}

		if(select(maximum + 1, &reader, NULL, NULL, NULL) < 0)
		{
			my_str("Error: error with select.\n");
			exit(0);
		}

		for(m = 0; m <= maximum; m++)
		{
			if(FD_ISSET(m, &reader))
			{
				if (offset == 0)
				{
					offset = m;
				}

				if(m == the_socket)
				{
					client = sizeof(struct sockaddr_in);
					new_actor = accept(the_socket, (struct sockaddr *)&client_add, (socklen_t*) &client);

					if(new_actor < 0)
					{
						my_str("Error: connection error.\n");
						exit(0);
					}

					else if (new_actor == 0)
					{
						my_str("Client closed\n");
					}

					else
					{
						my_str("new client. Welcome.\n");
						FD_SET(new_actor, &prime);

						if (new_actor > maximum)
						{
							maximum = new_actor;
						}
					}
				}

				else
				{
					if((n = recv(m, buffer, sizeof(buffer), 0)) <= 0)
					{
						if(n == 0)
						{
							my_str("Port ");
							my_str(argv[1]);
							my_str(" socket ");
							my_int(m);
							my_str(" disconnected\n");
						}

						close(m);
						FD_CLR(m, &prime);
					}

					else
					{
						ok = 1;

						if (ok)
						{
							message = buffer;
							for(i = 0; i <= maximum; i++)
							{
								if(FD_ISSET(i, &prime))
								{
									if(i != the_socket)
									{
										if(write(i, message, my_strlen(message)) < 0)
											my_str("Error: sending error");

										send(i, "\n\n", 1, 0);
									}
								}
							}
						}

						else
						{
							if(send(m, "invalid\n", 8, 0) < 0)
								my_str("Error: sending error");
						}
					}
				}
			}
		}
	}

	return 0;
}
