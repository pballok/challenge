#!/usr/bin/python3

import sys

def multiples(x, n):
    multiple = n
    while multiple < x:
        multiple += n
    print(multiple)
    
if len(sys.argv) != 2:
    print("Usage:", sys.argv[0], "<input file name>")
    sys.exit()
    
for l in open(sys.argv[1]):
    if l.strip() != "":
        numlist = l.split(",")
        multiples(int(numlist[0].strip()), int(numlist[1].strip()))


