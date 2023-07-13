#include <stdio.h>
#include <stdlib.h>


/**
* main - function that adds positive numbers.
* @argc: argument count
* @argv: arguments variable
*
* Return: always 0
*/

int main(int argc, char **argv)
{
int i, j, sum = 0;
char *yashe;


if (argc < 2)
{
printf("0\n");
return (0);
}


for (i = 1; argv[i]; i++)
{
j = strtol(argv[i], &yashe, 10);
if (*yashe)
{
printf("Error\n");
return (1);
}
else
{
sum += j;
}
}
printf("%d\n", sum);


return (0);
}
