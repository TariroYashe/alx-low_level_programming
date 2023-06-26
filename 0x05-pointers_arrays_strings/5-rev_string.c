#include "main.h"

/**
* rev_string - print a string in reverse
* @s: pointer to the string.
* Return: always 0
*/

void rev_string(char *s)
{
int span = 0, index = 0;
char temp;

while (s[index++])
span++;

for (index = span - 1; index >= span / 2; index--)

{
(temp = s[index]);
(s[index] = s[span - index - 1]);
(s[span - index - 1] = temp);
}
}

