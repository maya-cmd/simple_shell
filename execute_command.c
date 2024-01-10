#include "shell.h"

int command_execution(char **args_present, char **argv)
{
    pid_t process_id;
    int status;

    process_id = fork();
    if (process_id == 0)
    {
        if (execve(args_present[0],args_present, environ))
        {
            perror(argv[0]);
            exit(99);
        }
    }
    else
    {
        waitpid(process_id, &status, 0);
    }
    return(WEXITSTATUS(status));

}
