#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """ calculate how much water - The first and last are ignored"""

    if walls is None or walls == []:
        return 0
    if len(walls) == 1:
        return 0

    n = len(walls)
    water = 0

    for i in range(0, n):
        if walls[i] > 1:
            water += (walls[i]-1)

    return water
