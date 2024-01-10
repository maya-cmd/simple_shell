#include "shell.h"

int main(int ac, char **argv)
{
        char *command_entered = NULL, **args_present = NULL;
        int exit_code = 0;
        (void)ac;

        while (1)
        {
                command_entered = read_command_entered();
                if (command_entered == NULL)
                {
                        if (isatty(STDIN_FILENO))
                                write(STDOUT_FILENO, "\n", 1);
                        free(command_entered);
                        return (exit_code);
                }

                args_present = handling_command_entered_args(command_entered);
                if (!args_present)
                        continue;

                exit_code = command_execution(args_present, argv);

        }
}
