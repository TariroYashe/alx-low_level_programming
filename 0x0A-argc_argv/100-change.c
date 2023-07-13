#include <stdio.h>
#include <stdlib.h>

/**
* main -entry point
* @argc: arg count
* @argv: arr of string args
*
* Descrition: "prints the minimum number of coins to make change"
*
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
int amount, idx, coinCount = 0;
int coins[] = {25, 10, 5, 2, 1};

if (argc != 2)
{
printf("Error\n");
return (1);
}

amount = atoi(argv[1]);

for (idx = 0; idx < 5; idx++)
{
while (amount >= coins[idx])
{
amount = amount - coins[idx];
coinCount++;
}
}
printf("%d\n", coinCount);
return (0);
}
