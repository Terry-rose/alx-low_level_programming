#include <stdio.h>
#include <stdlib.h>

char *argstostr(int ac, char **av)
{
    int total_length = 0;
    int i, j;
    char *result;
    int position = 0;

    if (ac == 0 || av == NULL)
        return NULL;

    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j] != '\0'; j++)
            total_length++;
        total_length++; 
    }

    result = malloc(total_length + 1);
    if (result == NULL)
        return NULL;

    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j] != '\0'; j++)
        {
            result[position] = av[i][j];
            position++;
        }
        result[position] = '\n'; 
        position++;
    }

    result[position] = '\0'; 
    return result;
}
