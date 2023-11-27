#include <unistd.h>
#include <fcntl.h>
#include "main.h"

ssize_t _strlen(char *s);

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The content to add at the end of the file.
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)

{

int file_descriptor;
ssize_t bytes_written;

if (filename == NULL)
return (-1);

file_descriptor = open(filename, O_WRONLY | O_APPEND);
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

