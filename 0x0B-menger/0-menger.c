#include "menger.h"

/**
 * menger - 2d menger sponge print
 * @level: levels of sponge
 * Return: void
 */
void menger(int level)
{
	int size, x, y, r_x, r_y, z;

	size = pow(3, level);

	if (level < 0)
		return;
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			r_x = x;
			r_y = y;
			z = 0;
			while (r_x && r_y)
			{
				if (r_x % 3 == 1 && r_y % 3 == 1)
				{
					printf(" ");
					z = 1;
					break;
				}
				r_x /= 3;
				r_y /= 3;
			}
			if (!z)
				printf("#");
		}
		printf("\n");
	}
}
