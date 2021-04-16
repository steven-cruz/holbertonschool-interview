"""
    Given a list of non-negative integers representing walls of width 1
    calculate how much water will be retained after it rains.

    - walls is a list of non-negative integers.
    - Return: Integer indicating total amount of rainwater retained.
    - Assume that the ends of the list (before index 0 and after index
      walls[-1]) are not walls, meaning they will not retain water.
    - If the list is empty return 0.
"""


def rain(walls):
    """
        checks the list and the retained value.
        otherwise it returns 0
    """
    n = len(walls)
    t_water = 0

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, n):
            right = max(right, walls[j])

        t_water = t_water + (min(left, right) - walls[i])
    return t_water
