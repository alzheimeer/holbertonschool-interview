#!/usr/bin/python3
''' Rotate 2d matrix '''


def rotate_2d_matrix(matrix):
    ''' Rotates 2d matrix '''
    if not matrix or len(matrix) == 0:
        return
    matrix0 = [[0, 0, 0],
               [0, 0, 0],
               [0, 0, 0]]
    for i in range(len(matrix[0])):
        for j in range(len(matrix[0])):
            matrix0[i][j] = matrix[i][j]

    for i in range(len(matrix[0])):
        p = len(matrix[0]) - 1
        for j in range(len(matrix[0])):
            matrix[i][j] = matrix0[p][i]
            p = p - 1
