#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    n = len(walls)
    if (n <= 0):
        return (0)
    water = 0

    for i in range(1, n - 1):
        p1 = walls[i]
        for j in range(i):
            p1 = max(p1, walls[j])
        p2 = walls[i]
        for j in range(i + 1, n):
            p2 = max(p2, walls[j])
        x = min(p1, p2)
        water += x - walls[i]
    return (water)
