#include <stddef.h>
#include "main.h"

unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    char *ptr;
    int found;

    while (*s) {
        found = 0;
        ptr = accept;
        while (*ptr) {
            if (*s == *ptr) {
                found = 1;
                count++;
                break;
            }
            ptr++;
        }
        if (!found) {
            break;
        }
        s++;
    }

    return count;
}
