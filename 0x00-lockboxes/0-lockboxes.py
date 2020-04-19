#!/usr/bin/python3
""" boxes """


def canUnlockAll(boxes):

    if len(boxes) == 0:
        return True
    boxes[0].append(0)
    boxes[0] = list(set(boxes[0]))
    ff = boxes[0]
    if (len(boxes) == len(boxes[0])):
        return True

    for x in boxes[0]:
        ff = ff + boxes[x]
        ff = list(set(ff))
        if (len(boxes) != len(boxes[0])):
            boxes[0] = ff

    if (len(boxes) != len(boxes[0])):
        boxes[0] = ff

    try:
        return (canUnlockAll(boxes))
    except:
        return False
