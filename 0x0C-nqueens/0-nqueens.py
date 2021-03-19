
#!/usr/bin/python3
"""nqueens chessboard problem"""
import sys


def launch(foo):
    problems = []
    for row in range(0, foo):
        solve(foo, 0, row, problems)
    for solution in problems:
        print(solution)


def solve(size, col, row, sol_set, sol=[]):
    safe = is_safe(col, row, sol)
    if safe is False:
        return
    s = sol.copy()
    s.append([col, row])
    if col == size - 1:
        sol_set.append(sol)
    for i in range(0, size):
        solve(size, col + 1, i, sol_set, s)


def is_safe(col, row, sol):
    for idx in sol:
        if idx[0] == col or idx[1] == row:
            return False
        if idx[0] - idx[1] == col - row:
            return False
        if idx[0] + idx[1] == col + row:
            return False
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        x = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if x < 4:
        print("N must be at least 4")
        exit(1)
    launch(int(sys.argv[1]))
