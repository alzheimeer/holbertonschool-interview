#!/usr/bin/python3
def canUnlockAll(boxes):
    '''
    Method that determines if all the boxes can be opened.
    Args:
        boxes (lst): List of all the boxes.
    Returns:
        True (bool): for success,
        False (bool): In case of failure.
    '''
    if (type(boxes) is not list):
        return False

    if (len(boxes) == 0):
        return False

    f = list(range(1, len(boxes)))
    ff = []
    a = True
    
    while a:
        for x in boxes[0]:
            if x > len(boxes):
                x = 0
            if not boxes[x]:
                boxes[0].remove(x)
                ff.append(x)
                ff = list(set(ff))
            for y in boxes[x]:
                if (x is not None) and (y < len(boxes) and y != 0):
                    boxes[0] = boxes[0] + boxes[x]
                    boxes[0] = list(set(boxes[0]))
                    for z in boxes[0]:
                        if z > len(boxes):
                            boxes[0].remove(z)
                    boxes[x].clear()
                    ff.append(x)
                    ff = list(set(ff))
                    boxes[0].remove(x)
                else:
                    boxes[x].remove(y)
        if (len(boxes[0]) == 0):
            a = False

    if ff == f:
        return True
    return False
