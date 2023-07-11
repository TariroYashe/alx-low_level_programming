i#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
* check_num - check string there are digit
* @str: array str
* Return: 0 (success)
*/

int check_num(char *str)
{
unsigned int count = 0;

while (count < strlen(str))
{
if (!isdigit(str[count]))
{
return (0);
}
count++;
}
return (1);
}

/**
* main - print the name of the programme
* @argc: count the arguments
* @argv: arguments
* Return: 0 (success)
*/

int main(int argc, char *argv[])
{
int count;
int str_to_int;
int sum = 0;

count = 1;
while (count < argc)
{
if (check_num(argv[count]))
sum += str_to_int;
}
else
{
printf("Error\n");
return (1);
}
count++;
}
printf("%d\n", sum);
return (0);
}
