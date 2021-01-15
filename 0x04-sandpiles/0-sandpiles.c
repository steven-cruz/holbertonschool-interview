#include "sandpiles.h"
#include <stdio.h>

/**
 * sand_sum - sums two sandpiles
 * @grid1: sandpile, 3x3 matrix
 * @grid2: second sandpile, which will be 0 at then end
 */
static void sand_sum(int grid1[3][3], int grid2[3][3])
{
	int width, height;

	for (width = 0; width < 3; width++)
		for (height = 0; height < 3; height++)
			grid1[width][height] += grid2[width][height], grid2[width][height] = 0;

}

/**
 * is_stable - checks if sandpile is stable
 * @grid: sandpile, 3x3 matrix
 * Return: 1 if stable, or 0 on error
*/
static int is_stable(int grid[3][3])
{
	int width, height;

	for (width = 0; width < 3; width += 1)
		for (height = 0; height < 3; height++)
			if (grid[width][height] > 3)
				return (0);
	return (1);
}

/**
 * print_grid - Prints the grid
 * @grid: sandpile, 3x3 matrix
 * Return: 1 if stable, otherwise 0
*/
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	i = 0;
	for (; i <= 2; i++)
	{
		j = 0;
		for (; j <= 2; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * shift_sand - Topples sandpile
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */
static void shift_sand(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;
				if (i - 1 >= 0)
					grid2[i - 1][j]++;
				if (i + 1 <= 2)
					grid2[i + 1][j]++;

				if (j - 1 >= 0)
					grid2[i][j - 1]++;
				if (j + 1 <= 2)
					grid2[i][j + 1]++;
			}
}

/**
 * sandpiles_sum - Adds and topples two consecutive sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sand_sum(grid1, grid2);
	while (is_stable(grid1) == 0)
	{
		print_grid(grid1);
		shift_sand(grid1, grid2);
		sand_sum(grid1, grid2);
	}
}
