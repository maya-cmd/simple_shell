#include "shell.h"
char *_strdup(const char *s)
{
        char *ptr;
        int n, length = 0;

        if (s == NULL)
                return NULL;

        while (*s != '\0')
        {
                length++;
                s++;
        }

        s = s - length;
        ptr = malloc(sizeof(char) * (length + 1));
        if (ptr == NULL)
                return (NULL);

        for (n = 0; n <= length; n++)
                ptr[n] = s[n];

        return (ptr);
}
