#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Determine if a number is positive.
 * negagive or zero.
 * Return: Always 0 (Success)
 */
int main(void)
{
	srand(time(0));
	int n = rand();

	std::cout << "The number is " << n << " and it is ";
	if (n > 0)
	{
	std::cout << "positive";
	}
	else if (n == 0)
	{
	std::cout << "zero";
	}
	else
	{
	std::cout << "negative";
	}
	std::cout << std::endl;
	return (0);
}
