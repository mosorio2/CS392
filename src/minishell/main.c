#include "minishell.h"

void handler(int sig)
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		my_char('\n');
	}
	else {
		my_str("Error: incorrect directory. See help.\n");
	}
}

int main(int argc, char**argv)
{
	int n;
	int pid;
	char* str;
	char cwd[1024];
	char** inp;

	str = (char*)malloc(256*sizeof(char));

	while (1) {
		signal(SIGINT, handler);
		my_str("MINISHELL: ");

		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			my_str(cwd);
		}
		else {
			my_str("Error: directory does not exist. Type 'help' for info.\n");
			return -1;
		}
		
		my_str(" $: ");
		n = read(0, str, 256);

		str[n-1] = '\0';
		if (n > 1) {
			inp = my_str2vect(str);
			if (my_strcmp(inp[0], "cd") == 0) {
				if (inp[1] != '\0') {
					if (chdir(inp[1]) < 0) {
						my_str("Error: incorrect path name given. Try again.\n");
					}
				}
			}
			else if (my_strcmp(inp[0], "help") == 0) {
				my_str("cd directory: changes the current working directory to specified directory.\nexit: exits the minishell.\nhelp: prints a help message listing the built in commands.\ntype a program name to execute an external program\n");
			}			
			else if (my_strcmp(inp[0], "exit") == 0) {
				my_str("Exiting... Thanks for using minishell!\n");
				exit(0);
			}
			else if (inp[0] != NULL) {
				if ((pid = fork()) == -1) {
					my_str("Error: error during forking. Please try again.");
				}
				else if (pid > 0) {
					wait(NULL);
				}
				else {
					if (execvp(inp[0], inp) == -1) {
						my_str("Error: program cannot be executed. Please check spelling of program and try again.\n");
					}
				}
			}
			else {
				my_str("Error: type 'help' for info.\n");
			}
		}	
	}
	free(str);
	return 0;
}