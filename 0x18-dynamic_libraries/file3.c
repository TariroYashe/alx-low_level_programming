#include "main.h"

/**
* _strcat - Concatenates two strings
* @dest: The destination string
* @src: The source string to append
*
* Return: A pointer to the destination string
*/
char *_strcat(char *dest, char *src)
{
int dest_len = _strlen(dest);
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[dest_len + i] = src[i];
}

dest[dest_len + i] = '\0';
return (dest);
}

/**
* _strncat - Concatenates n characters from one string to another
* @dest: The destination string
* @src: The source string to append
* @n: The maximum number of characters to append
*
* Return: A pointer to the destination string
*/
char *_strncat(char *dest, char *src, int n)
{
int dest_len = _strlen(dest);
int i;

for (i = 0; src[i] != '\0' && i < n; i++)
{
dest[dest_len + i] = src[i];
}

dest[dest_len + i] = '\0';
return (dest);
}

/**
* _strncpy - Copies n characters from one string to another
* @dest: The destination string
* @src: The source string
* @n: The number of characters to copy
*
* Return: A pointer to the destination string
*/
char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; src[i] != '\0' && i < n; i++)
{
dest[i] = src[i];
}

for (; i < n; i++)
{
dest[i] = '\0';
}

return (dest);
}

/**
* _strcmp - Compares two strings
* @s1: The first string to compare
* @s2: The second string to compare
*
* Return: (0)
*/
int _strcmp(char *s1, char *s2)
{
/* Your implementation for _strcmp here */
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
* _memset - Fills memory with a constant byte
* @s: The memory area to fill
* @b: The constant byte to set
* @n: The number of bytes to fill
*
* Return: A pointer to the memory area s
*/
char *_memset(char *s, char b, unsigned int n)
{
while (n-- > 0)
{
*s = b;
s++;
}
return (s);
}
