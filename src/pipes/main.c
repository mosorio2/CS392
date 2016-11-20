#include "pipes.h"

int main(int argc, char**argv)
{
	int fd[2];
    int the_fd[2];
    pid_t the_child;
    char buff[100];
    char* str;
    int n;

    if (argc < 2)
    {
        my_str("usage: ./pipes arg1 [arg2] [arg3]... \n");
        return -1;
    }
    else
    {

        if (pipe(fd) == -1)
        {
            exit(-1);
        }
        if((the_child = fork()) == -1)
        {
            exit(-1);
        }
        else if(the_child > 0)
        {
            if(close(fd[0]))
                return -1;
            str = my_vect2str(&argv[1]);
            my_str(">Parent: ");
            my_str(str);
            my_char('\n');
            if((write(fd[1], str, (my_strlen(str)+1))) < 0)
                return -1;
            wait(NULL);
            exit(0);
        }
        else if (the_child == 0)
        {
            if(close(fd[1]))
                return -1;
            if(pipe(the_fd))
            {
                return -1;
            }
            if((the_child = fork()) == -1)
            {
                exit(-1);
            }
            else if (the_child > 0)
            {
                if(close(the_fd[0]))
                {
                    return -1;
                }
                str = my_vect2str(&argv[1]);
                n = read(fd[0], buff, sizeof(buff));
                if(n < 0)
                    return -1;
                my_str(">Child: ");
                my_str(buff);
                my_char('\n');
                if((write(the_fd[1], buff, (my_strlen(buff)+1))) < 0)
                    return -1;
                wait(NULL);
                exit(0);
            }
            else if (the_child == 0)
            {
                if(close(the_fd[1]))
                {
                    return -1;
                }
                str = my_vect2str(&argv[1]);
                n = read(the_fd[0], buff, sizeof(buff));
                if (n < 0)
                    return -1;
                my_str(">Grandchild: ");
                my_str(buff);
                my_char('\n');
                exit(0);
            }
        }
    }
        return 0;
}
