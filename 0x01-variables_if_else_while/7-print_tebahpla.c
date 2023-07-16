#include <stdio.h>
/**
 * main - program that prints the lowercase alphabet in reverse.
 * followed by a new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char le;

	for (le = 'z'; le >= 'a'; le--)
		putchar(le);
	putchar('\n');
	return (0);
}
