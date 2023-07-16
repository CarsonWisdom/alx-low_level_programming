#include <stdio.h>
/**
 * main - program that prints all possible combinations.
 * of single-digit numbers.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i <= 9; i++)
	{
		putchar(i + '0');
		for (j = 0; j <= 9; j++)
		{
			putchar(',');
			putchar(' ');
			putchar(j + '0');
		}
	}
	return (0);
}
