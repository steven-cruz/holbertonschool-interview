#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    memo = {0: 0}

    for i in range(1, total + 1):
        memo[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            memo[i] = min(memo[current] + 1, memo[i])

    if memo[total] == total + 1:
        return -1

    return memo[total]
