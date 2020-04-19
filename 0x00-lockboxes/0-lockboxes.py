#!/usr/bin/python3
def canUnlockAll(boxes):
    '''box key'''
    f = list(range(1, len(boxes)))
    ff = []
    a = True

    if not boxes:
        return False
    if len(boxes) is 0:
        return True
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
