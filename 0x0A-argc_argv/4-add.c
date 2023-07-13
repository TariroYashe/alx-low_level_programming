#include <stdio.h>
#include <stdlib.h>

/**
* main - adds positive numbers.
* @argc: arg count
* @argv: arr of args
*
* Description: "adds positive numbers."
*
* Return: Always 0 (success) otherwise 1 (error)
*
*/

int main(int argc, char *argv[])
{
long int total = 0;
int idx;
int num;

if (argc == 1)
{
printf("0\n");
return (0);
}

for (idx = 1; idx < argc; idx++)
{
num = atoi(argv[idx]);

if (num <= 0 && argv[1][0] != '0')
{
printf("Error\n");
return (1);
}
total += num;
}
printf("%ld\n", total);
return (0);
}
