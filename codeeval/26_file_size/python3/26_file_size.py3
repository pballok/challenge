#!/usr/bin/python3

import sys
import os

if len(sys.argv) != 2:
    print("Usage:", sys.argv[0], "<input file>")
    sys.exit()

print(os.path.getsize(sys.argv[1]))

