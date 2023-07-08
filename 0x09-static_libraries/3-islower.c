#include "main.h"

/**
* _islower - tests whether a character is a lower case letter
* Desxription: "a function that checks for lowercase character"
* @c: character to test.
* Return: 1 if lowercase letter, 0 if not.
*/

int _islower(int c)
{
if (c >= 'a' && c <= 'z')
return (1);
else
return (0);
}
