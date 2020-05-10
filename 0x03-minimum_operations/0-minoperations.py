#!/usr/bin/python3
"""
 minOperations
"""


def minOperations(n):
    """This method returns the number of operations to copy paste
    Args:
        n: given number 
    Returns:
        num: number of operations.
    """
    num = 0
    if (n < 2 or type(n) != int):
        return 0
    while (n != 1):
        if (n % 2 == 0):
            n = n / 2
            num = num + 2
        elif (n % 3 == 0):
            n = n / 3
            num = num + 3
        elif (n % 5 == 0):
            n = n / 5
            num = num + 5
        else:
            num = n
            n = 1
    return num