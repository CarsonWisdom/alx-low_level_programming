#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @m: string containing binary number
 * Return: converted number
 */
unsigned int binary_to_uint(const char *m)
{
	int i;
	unsigned int dec_val = 0;

	if (!m)
		return (0);

	for (i = 0; m[i]; i++)
	{
		if (m[i] < '0' || m[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (m[i] - '0');
	}
	return (dec_val);
}
