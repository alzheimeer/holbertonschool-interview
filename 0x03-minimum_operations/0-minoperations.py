#!/usr/bin/python3
"""minOperations"""


def minOperations(n):
    """number of operations to copy paste
    Args:
        n: given number
    Returns:
        num: number of operations.
    """
    p = 2
    num = 0
    if type(n) != int or n <= 1:
        return 0
    while n != 1:
        if n % p == 0:
            n = n / p
            num = num + p
        else:
            p = p + 1
    return int(num)
