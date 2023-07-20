#include <stdio.h>
#include "main.h"
/**
 * main - prints the numbers from 1 to 100
 * multiples of three print Fizz instead of the number
 * multiples of five print Buzz
 * multiples of both three and five print FizzBuzz.
 * Return: void
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%i", i);
		if (i < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
