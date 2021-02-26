#include "slide_line.h"

/**
 * slide_left - Slide to left side
 * @line: array to slide left
 * @size: size of array
 * Return: 1 on success, 0 otherwise
 */

int slide_left(int *line, size_t size)
{
	size_t s_right = 0;
	size_t s_left = 0;
	int placehold = 0;
	int success = 1;

	for (; s_right < size; s_right++)
	{
		if (line[s_right] == 0)
			continue;
		if (placehold == 0)
			placehold = line[s_right];
		else if (placehold == line[s_right])
		{
			placehold = line[s_right];
			line[s_left] = placehold + line[s_right];
			placehold = 0;
			s_left++;
		}
		else
		{
			line[s_left] = placehold;
			placehold = line[s_right];
			s_left++;
		}
	}
	if (placehold)
	{
		line[s_left] = placehold;
		s_left++;
	}
	for (; s_left < s_right; s_left++)
		line[s_left] = 0;
	return (success);
}

/**
 * slide_right - Slide to right side
 * @line: array to slide left
 * @size: size of the array
 * Return: 1 on success, 0 otherwise
 */

int slide_right(int *line, size_t size)
{
	size_t s_right = size;
	size_t s_left = size;
	int placehold = 0;
	int success = 1;

	for (s_left = size; s_left > 0; s_left--)
	{
		if (line[s_left - 1] == 0)
			continue;
		if (placehold == 0)
			placehold = line[s_left - 1];
		else if (placehold == line[s_left - 1])
		{
			placehold = line[s_left - 1];
			line[s_right - 1] = placehold + line[s_left - 1];
			placehold = 0;
			s_right--;
		}
		else
		{
			line[s_right - 1] = placehold;
			placehold = line[s_left - 1];
			s_right--;
		}
	}
	if (placehold)
	{
		line[s_right - 1] = placehold;
		s_right--;
	}
	for (; s_left < s_right; s_right--)
		line[s_right - 1] = 0;
	return (success);
}

/**
 * slide_line - Slides an integer array @line to left or right
 * @line: integer array to slide
 * @size: size of integer line
 * @direction: direction of slide integer array
 * Return: 1 on success, othewise 0
 */

int slide_line(int *line, size_t size, int direction)
{
	int zilch = 0;
	
	if (!line || !size)
		return (zilch);

	else if (direction == -1)
		zilch = slide_left(line, size);
	else if (direction == 1)
		zilch = slide_right(line, size);
	return (zilch);
}
