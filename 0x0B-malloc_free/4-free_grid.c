#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_grid -  frees a 2D grid in alloc_grid.c
* @grid: 2D grid
* @height: height of grid dimension
* Description: free memory of grid
* Return: nothing
*/

void free_grid(int **grid, int height)
{
int x;

for (x = 0; x < height; x++)
{
free(grid[x]);
}

free(grid);
}
