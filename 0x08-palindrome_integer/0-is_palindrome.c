#include "palindrome.h"

/**
 * is_palindrome - determines wheter or not an unsigned integer is a palindrome
 *
 * @n: number to be checked
 *
 * Return: 1 if palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long idx = 10;
	unsigned long tens = 0;
	unsigned long b = 0;
    int flag = 0;

	while (n / idx >= 10)
		idx *= 10;
	while (n > 9)
	{
		tens = (n / idx);
		b = (n % 10);
		if (tens != b)
			return (flag);
		n = (n % idx) / 10;
		idx /=  100;
	}
	return (1);
}
