#!/usr/bin/python3

import sys

if len(sys.argv) != 2:
    print("Usage:", sys.argv[0], "<input file>")
    sys.exit()

f = open(sys.argv[1])

total = 0
for line in [l.strip() for l in f.readlines()]:
    if line != "":
        total += int(line)

print(total)

