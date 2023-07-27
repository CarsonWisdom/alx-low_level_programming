#include "main.h"
/**
 * *leet - function that encodes a string into 1337.
 * @n: input value
 * Return: n value
 */
char *leet(char *n)
{
	int i, j;
	char s1[] = "aAeEoOtT";
	char s2[] = "44330011";

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ([i] == s1[j])
			{
				n[i] = s2[j];
			}
		}
	}
	return (n);
}
