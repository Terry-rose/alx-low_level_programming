#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void close_fd_error(int fd);

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])

{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close_fd_error(fd_from);
exit(99);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)

{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)

{
dprintf(2, "Error: Can't write to %s\n", argv[2]);
close_fd_error(fd_from);
close_fd_error(fd_to);
exit(99);
}
}

if (bytes_read == -1)

{
dprintf(2, "Error: Can't read from file %s\n", argv[1]);
close_fd_error(fd_from);
close_fd_error(fd_to);
exit(98);
}

close_fd_error(fd_from);
close_fd_error(fd_to);
return (0);
}

/**
 * close_fd_error - Closes a file descriptor and exits with an error message if closing fails.
 * @fd: The file descriptor to close.
 */
void close_fd_error(int fd)

{
if (close(fd) == -1)
{
dprintf(2, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

