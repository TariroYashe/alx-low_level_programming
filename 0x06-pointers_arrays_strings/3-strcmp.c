#include "main.h"

/**
* _strcmp - compares two strings.
* @p1: pointer to first string.
* @p2: pointer to second string.
* Return: value<0 if string < the other. value>0 if string > the other & 0 if =
*/

int _strcmp(char *p1, char *p2)
{
int counter, compare_value;

counter = 0;
while (p1[counter] == p2[counter] && p1[counter] != '\0')
{
counter++;
}
compare_value = p1[counter] - p2[counter];
return (compare_value);
}
