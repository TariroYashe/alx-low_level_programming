#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
/*
* Define a symbolic constant for buffer size
*/


/**
* read_textfile - Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w - actual number of bytes read and printed
*        0 when function fails or filename is NULL.
*/

ssize_t read_textfile(const char *filename, size_t letters)

{
int fd;/*
	*A file descriptor used to represent the opened file
	*/
ssize_t w = 0;/*
	*A variable to store the actual number of bytes read and printed
	*/
ssize_t t;/*
	*A variable to store the number of bytes read in each iteration
	*/
char buf[BUF_SIZE];/*
	*An array to hold the data read from the file,
	*using the symbolic constant BUF_SIZE as the buffer size
	*/

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

while (letters > 0 && (t = read(fd, buf, sizeof(buf))) > 0)
{
/*
 * it calculate number of letters to print
 */
ssize_t print_bytes = ((ssize_t)letters < t) ? (ssize_t)letters : t;

w += write(STDOUT_FILENO, buf, print_bytes);
letters -= (size_t)print_bytes;
}

close(fd);
return (w);
}
