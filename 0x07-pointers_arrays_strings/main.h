#ifndef MAIN_H
#define MAIN_H

char *_memset(char *s, char b, unsigned int n);

char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strcmp(const char *str1, const char *str2);

char *_strchr(char *s, char c);

unsigned int _strspn(char *s, char *accept);

char *_strpbrk(char *s, char *accept);

char *_strstr(char *haystack, char *needle);

int _putchar(char c);
void print_chessboard(char (*a)[8]);

void print_diagsums(int *a, int size);

#define MAX_SIZE 100
#define PI 3.14159265359
#endif /* MAIN_H */
