CC=gcc
BASEDIR=../..

all:
	$(CC) -c *.c -std=c90 -Wall -Werror --pedantic -L$(BASEDIR)/lib -lmy
	$(CC) *.o -L$(BASEDIR)/lib -lmy -o minishell

clean:
	rm -f *.o
	rm -f *.out
	rm -f *~
	rm -f *.swp

fclean: clean
	rm -f minishell

re: fclean all