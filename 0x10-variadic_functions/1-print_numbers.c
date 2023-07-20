#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
* print_numbers - Prints numbers, followed by a new line.
* @separator: The string to be printed between numbers.
* @n: The number of integers passed to the function.
* @...: A variable number of numbers to be printed.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list numb;
unsigned int index;


va_start(numb, n);


for (index = 0; index < n; index++)
{
if (!separator)
printf("%d", va_arg(numb, int));

else if (separator && index == 0)
printf("%d", va_arg(numb, int));

else
printf("%s%d", separator, va_arg(numb, int));
}
va_end(numb);
printf("\n");
}
