#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """ calculate how much water - The first and last are ignored"""

    if walls is None or walls == []:
        return 0
    if len(walls) <= 3:
        return 0

    n = len(walls)
    water = 0

    for i in range(1, n-1):
        water += walls[i]

    return water
