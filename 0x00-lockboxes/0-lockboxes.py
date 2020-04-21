#!/usr/bin/python3
def canUnlockAll(boxes):
    '''
    Method that determines if all the boxes can be opened.
    '''
    if (len(boxes) == 0):
        return False
    box = list(range(len(boxes)))
    keys = [False]*len(boxes)
    keys[0] = True

    for c in box:
        for i in box:
            if keys[i] is True:
                for k in boxes[i]:
                    if k in box and keys[k] is False:
                        keys[k] = True

    if False in keys:
        return False
    return True
