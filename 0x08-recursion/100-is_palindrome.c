#include "main.h"

/**
* palindrome1 - obtains length of a
* @i: string
* @j: integer to count length
* Return: 1 On success
* -1 On error
*/

int palindrome1(char *i, int j)
{
if (*i == 0)
return (j - 1);
return (palindrome1(i + 1, j + 1));
}

/**
* palindrome2 - compares string vs string reverse
* @a: string
* @l: length
* Return: 1 On success
* -1 On error
*/

int palindrome2(char *a, int l)
{
if (*a != *(a + l))
return (0);
else if (*a == 0)
return (1);
return (palindrome2(a + 1, l - 2));
}

/**
* is_palindrome - checks if a string is a palindrome
* @s: string
* Return: 1 On success
* -1 On error
*/

int is_palindrome(char *s)

{
int l;

l = palindrome1(s, 0);
return (palindrome2(s, l));
}
