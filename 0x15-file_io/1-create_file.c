#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

ssize_t _strlen(char *s);

/**
 * create_file - Creates a file and writes text to it.
 * @filename: The name of the file to create.
 * @text_content: The content to write to the file.
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)

{

int file_descriptor;
ssize_t bytes_written;
if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (file_descriptor == -1)
return (-1);

if (text_content != NULL)

{

bytes_written = write(file_descriptor, text_content, _strlen(text_content));
if (bytes_written == -1 || bytes_written != _strlen(text_content))

{

close(file_descriptor);
return (-1);

}
}

close(file_descriptor);
return (1);
}


/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 * Return: The length of the string.
 */
ssize_t _strlen(char *s)

{
ssize_t len = 0;

while (s[len] != '\0')
len++;

return (len);
}

