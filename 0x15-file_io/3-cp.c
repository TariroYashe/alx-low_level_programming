#include "main.h"

/**
* create_buffer - allocate bytes for storing.
* @fyle: name of file which the buffer is storing characters
* Return: a pointer to the newly-allocated buffer, or exit on failure.
*/
char *create_buffer(char *fyle)
{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
/* Print error message to stderr */
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fyle);
exit(99);
}
return (buffer);
}


/**
* close_fyle - the func closes file descriptors.
* @file_descriptor: file descriptor to be closed.
*/
void close_fyle(int file_descriptor)
{
int c;
c = close(file_descriptor);
if (c == -1)
{
/* Print error message to stderr */
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
exit(100);
}
}

/**
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: If the argument count is incorrect, exit with code 97.
*  if file_to already exists, truncate it
* If file_from does not exist or cannot be read, exit with code 98.
* If file_to cannot be created or written to, exit with code 99.
* If file_to or file_from cannot be closed, exit with code 100.
* If the file already exists, do not change the permissions
*/
int main(int argc, char *argv[])
{
int from, to, ried, wryt;
char *buffer;
if (argc != 3)
{
/* Print usage message to stderr */
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
ried = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || ried == -1)
{
/* Print error message to stderr */
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
wryt = write(to, buffer, ried);
if (to == -1 || wryt == -1)
{
/* Print error message to stderr */
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
ried = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (ried > 0);
free(buffer);
close_fyle(from);
close_fyle(to);
return (0);
}
