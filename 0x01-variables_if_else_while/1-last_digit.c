#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point
 *
 * Description: display the last digit of randomly generated number
 *
 * Return: always 0 (successful)
 */

int main(void)

{
int n;
int ld;

srand(time(0));
n = rand() - RAND_MAX / 2;

if ((n % 10) > 5)

{
printf("Last digit of %d is %d and is greater than 5\n", n, ld);
}

else if ((n % 10) < 6 && (n % 10) == 0)

{
prinf("Last digit of %d is %d and is less than 6 and not 0\n", n, ld);
}

else

{
printf("Last digit of %d is %d and is 0\n", n, ld);
}

return (0);
}
