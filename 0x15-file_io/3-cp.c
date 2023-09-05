#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits the
 * program with a specified code.
 *
 * @code: The exit code to be used when the program exits.
 * @format: The format string for the error message.
 * @...: Additional arguments for formatting the error message.
 *
 * Description:
 * - This function prints an error message to the
 *   standard error (stderr) using dprintf.
 * - The error message is formatted based on the
 *   format string and additional arguments.
 * - It then exits the program with the specified exit code.
 */
void error_exit(int code, const char *format, ...);


/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description:
 * - If the argument count is incorrect - exit code 97.
 * - If file_from does not exist or cannot be read - exit code 98.
 * - If file_to cannot be created or written to - exit code 99.
 * - If file_to or file_from cannot be closed - exit code 100.
 * - Permissions of the created file: rw-rw-r--.
 * - If the file already exists, do not change the permissions.
 * - You must read 1,024 bytes at a time from the
 *   file_from to make fewer system calls. Use a buffer.
 * - You are allowed to use dprintf.
 */
int main(int argc, char *argv[])

{
const char *file_from;
const char *file_to;
int fd_from;
int fd_to;
char buffer[BUFFER_SIZE];
ssize_t bytes_read;

if (argc != 3)
{
error_exit(97, "Usage: %s file_from file_to\n", argv[0]);
}

file_from = argv[1];
file_to = argv[2];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
{
error_exit(98, "Error: Can't read from file %s\n", file_from);
}

fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (fd_to == -1)
{
error_exit(99, "Error: Can't write to file %s\n", file_to);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
ssize_t bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
error_exit(99, "Error: Can't write to file %s\n", file_to);
}
}

if (bytes_read == -1)
{
error_exit(98, "Error: Can't read from file %s\n", file_from);
}

if (close(fd_from) == -1)
{
error_exit(100, "Error: Can't close fd %d\n", fd_from);
}

if (close(fd_to) == -1)
{
error_exit(100, "Error: Can't close fd %d\n", fd_to);
}

return (0);
}

void error_exit(int code, const char *format, ...)
{
va_list args;
va_start(args, format);
dprintf(STDERR_FILENO, format, args);
va_end(args);
exit(code);
}
