#include "main.h"
/**
 * *cap_string - function that capitalizes all words of a string.
 * @str: string to be capitalized
 * Return: Pointer to be changed string.
 */
char *cap_string(char *str)
{
	int index = 0;

	while (str[index])
	{
		while (!(str[index] >= 'a' && str[index] <= 'z'))
			index++;
		if (str[index - l] == ' ' ||
				str[index - l] == '\t' ||
				str[index - l] == '\n' ||
				str[index - l] == ',' ||
				str[index - l] == ';' ||
				str[index - l] == '.' ||
				str[index - l] == '!' ||
				str[index - l] == '?' ||
				str[index - l] == '"' ||
				str[index - l] == '(' ||
				str[index - l] == ')' ||
				str[index - l] == '{' ||
				str[index - l] == '}' ||
				index == 0)
			str[index] -= 32;
	}
	return (str);
}
