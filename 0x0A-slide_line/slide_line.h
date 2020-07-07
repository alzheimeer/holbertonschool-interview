#ifndef _H_
#define _H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void order(int *line, size_t size, int direction);


#endif
