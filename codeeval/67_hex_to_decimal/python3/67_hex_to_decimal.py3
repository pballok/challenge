#!/usr/bin/python3

import sys

if len(sys.argv) != 2:
    print("Usage:", sys.argv[0], "<input file>")
    sys.exit()

for line in open(sys.argv[1]):
    if len(line) != 1:
        print(int(line, 16))

