#include <stdio.h>
#include "main.h"

/**
* main - prints all arguments it receives
* @argc: number of arguments
* @argv: array of argements
* Return: 0
*/

int main(int argc, char *argv[])
{
int x;
for (x = 0; x < argc; x++)
{
printf("%s\n", argv[x]);
}
return (0);
}
