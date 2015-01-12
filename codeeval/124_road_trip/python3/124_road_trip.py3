#!/usr/bin/python3

import sys

if len(sys.argv) != 2:
    print("Usage:", sys.argv[0], "<input file>")
    sys.exit()

for line in open(sys.argv[1]):
    distances = []
    for city in line.split(";"):
        dist = city.split(",")
        if len(dist) > 1:
            distances.append(int(dist[1]))

    total = 0
    first = True
    for stop in sorted(distances):
        if first:
            first = False
        else:
            print(",", end="")
        print(stop - total, end="")
        total = stop
    print("")
            
