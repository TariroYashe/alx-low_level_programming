#include "main.h"
/**
* leet - function that encodes a string into 1337.
* letter a and A are replaced by 4
* letter e and E are replaced by 3
* letter o and O are replaced by 0
* letter t and T are replaced by 7
* letter l and L are replaced by 1
* @p: pointer to string.
* Return: pointer to string.
*/

char *leet(char *p)
{
int str_length, leet_count;
char leet_letter[] = "aAeEoOtTlL";
char leetnumbers[] = "4433007711";

str_length = 0;

while (p[str_length] != '\0')

{
leet_count = 0;
while (leet_count < 10)
{
if (leet_letter[leet_count] == p[str_length])
{
p[str_length] = leetnumbers[leet_count];
}
leet_count++;
}
str_length++;
}
return (p);
}
