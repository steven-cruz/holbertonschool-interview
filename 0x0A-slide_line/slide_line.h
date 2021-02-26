#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1


int slide_left(int *line, size_t size);
int slide_right(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif /*SLIDE_LINE_H*/
