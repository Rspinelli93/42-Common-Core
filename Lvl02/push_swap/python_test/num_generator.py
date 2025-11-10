#!/usr/bin/env python3
"""
num_generator.py
----------------
Generates 40 test files with random number sets for the push_swap project.

How to use:
1. cd ~/Common-Core/Lvl02/push_swap/python_test
2. python3 num_generator.py
"""

import os
import random

# Folder to save test files
folder = os.path.expanduser("~/Common-Core/Lvl02/push_swap/python_test/test")
os.makedirs(folder, exist_ok=True)

# Helper functn
def generate_test(filename, count, min_n=-1000, max_n=1000):
    numbers = random.sample(range(min_n, max_n), count)
    with open(os.path.join(folder, filename), "w") as f:
        f.write(" ".join(map(str, numbers)))

# Generate tests
for i in range(1, 41):
    if i <= 10:
        count = random.randint(10, 50)
    elif i <= 20:
        count = 100
    elif i <= 30:
        count = 200
    else:
        count = 500
    generate_test(f"test{i}.txt", count)

print(f"✅ 40 test files created in {folder}")
