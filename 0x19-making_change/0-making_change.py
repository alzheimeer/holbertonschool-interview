#!/usr/bin/python3
"""Mao Coins"""


def makeChange(coins, total):
    """Tell coins required for a sum"""
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1

    fla = sorted(coins)
    fla = fla[::-1]

    coins = 0
    xx = total
    for c in fla:
        while (xx - c >= 0):
            xx = xx - c
            coins = coins + 1

    if xx != 0 and xx - fla[-1] < 0:
        return -1
    return coins