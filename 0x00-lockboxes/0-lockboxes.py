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
    box = list(range(len(boxes)))
    keys = [False]*len(boxes)
    keys[0] = True
    for k in boxes[0]:
        if k in box:
            keys[k] = True

    for c in range(len(boxes)-2):
        for i in range(1, len(boxes)):
            if keys[i] is True:
                for k in boxes[i]:
                    if k in box:
                        keys[k] = True

    if False in keys:
        return False
    return True
