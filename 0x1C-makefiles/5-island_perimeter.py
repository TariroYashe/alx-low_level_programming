#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    # Get the width and height of the grid
    width = len(grid[0])
    height = len(grid)

    # Initialize counters for edges and size
    edges = 0
    size = 0

    # Iterate through each cell in the grid
    for i in range(height):
        for j in range(width):
            # If the cell is land, increment the size
            if grid[i][j] == 1:
                size += 1
                # Check the left neighbor for land, increment edges if found
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                # Check the top neighbor for land, increment edges if found
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1

    # Calculate the perimeter using the formula: size * 4 - edges * 2
    return size * 4 - edges * 2
