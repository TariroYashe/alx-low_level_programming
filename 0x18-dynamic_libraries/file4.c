#include "main.h"

/**
* _memcpy - Copies memory area from src to dest
* @dest: The destination memory area
* @src: The source memory area
* @n: The number of bytes to copy
*
* Return: A pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}

/**
* _strchr - Locates the first occurrence of a character in a string
* @s: The string to search
* @c: The character to find
*
* Return: A pointer to the first occurrence of c in s, or NULL if not found
*/
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
if (c == '\0')
{
return (s); /* Special case for '\0' */
}
return (NULL);
}

/**
* _strspn - Calculates the length of the initial segment
* @s: The string to search
* @accept: The set of bytes to accept
*
* Return: The number of bytes in the initial segme
*/
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int found = 1;
while (*s && found)
{
found = 0;
int i = 0;
while (accept[i])
{
if (*s == accept[i])
{
found = 1;
break;
}
i++;
}
if (found)
{
count++;
s++;
}
}
return (count);
}

/**
* _strpbrk - Searches a string for any of a set of bytes
* @s: The string to search
* @accept: The set of bytes to search for
*
* Return: A pointer
*/
char *_strpbrk(char *s, char *accept)
{
while (*s)
{
int i = 0;
while (accept[i])
{
if (*s == accept[i])
{
return (s);
}
i++;
}
s++;
}
return (NULL);
}

/**
* _strstr - Locates a substring within a string
* @haystack: The string to search in
* @needle: The substring to find
*
* Return: apointer
*/
char *_strstr(char *haystack, char *needle)
{
while (*haystack)
{
char *h = haystack;
char *n = needle;
while (*n && (*h == *n))
{
h++;
n++;
}
if (*n == '\0')
{
return (haystack);
}
haystack++;
}
return (NULL);
}
