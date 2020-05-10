#!/usr/bin/python3
"""minOperations"""


def minOperations(n):
    """This method returns the number of operations to copy paste
    Args:
        n: given number 
    Returns:
        num: number of operations.
    """
    num = 0
    if type(n) != int or n <= 1:
        return 0
    else:
        while n != 1:
            if n % 2 == 0:
                n = n / 2
                num = num + 2
            else:
                num = num + n
                n = n / n
    return int(num)