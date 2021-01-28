#!/usr/bin/python3

import sys

file_size = 0
stats = {"200": 0, "301": 0, "400": 0, "401": 0,
         "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i, line in enumerate(sys.stdin, 1):
        split_args = line.split(" ")
        if len(split_args) < 2:
            continue
        if split_args[-2] in stats:
            stats[split_args[-2]] = stats[split_args[-2]] + 1
        file_size = file_size + eval(split_args[-1])
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key in sorted(stats.keys()):
                if stats[key] > 0:
                    print("{}: {}".format(key, stats[key]))
finally:
    print("File size: {}".format(file_size))
    for key in sorted(stats.keys()):
        if stats[key] > 0:
            print("{}: {}".format(key, stats[key]))
