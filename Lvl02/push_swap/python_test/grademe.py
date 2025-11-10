#!/usr/bin/env python3
"""
grademe.py - 42 Push_Swap Tester

Usage:
1. Go to the push_swap folder:
*   cd ~/Common-Core/Lvl02/push_swap
2. Make sure your push_swap executable exists:
*   make
3. Generate tests (optional):
*   python3 python_test/num_generator.py
4. Run tester (80% minimum grade checks):
*   ./python_test/grademe.py
5. Run strict tester (100% full project validation):
*   ./python_test/grademe.py --strict
"""

import os
import subprocess
import argparse

# ANSI color codes
GREEN = "\033[32m"
RED = "\033[31m"
RESET = "\033[0m"

# Get folder locations
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
TESTS_FOLDER = os.path.join(SCRIPT_DIR, "test")
PUSH_SWAP_EXEC = os.path.join(os.path.dirname(SCRIPT_DIR), "push_swap")

# Define operation limits
LIMITS_80 = {
    100: 1100,
    500: 8500
}

LIMITS_STRICT = {
    100: 700,
    500: 5500
}

# Parse command line arguments
parser = argparse.ArgumentParser(description="Run push_swap tests")
parser.add_argument("--strict", action="store_true", help="Use strict 100% validation limits")
args = parser.parse_args()

limits = LIMITS_STRICT if args.strict else LIMITS_80

# Gather all test files
test_files = sorted([f for f in os.listdir(TESTS_FOLDER) if f.endswith(".txt")])

for test_file in test_files:
    file_path = os.path.join(TESTS_FOLDER, test_file)
    
    # Read numbers from test file
    with open(file_path, "r") as f:
        numbers = f.read().split()
    
    # Run push_swap with numbers as argv
    try:
        result = subprocess.run(
            [PUSH_SWAP_EXEC] + numbers,
            capture_output=True,
            text=True,
            check=True
        )
    except subprocess.CalledProcessError as e:
        print(f"{RED}Error running push_swap with {test_file}:{RESET}")
        print(e.stderr)
        continue
    except FileNotFoundError:
        print(f"{RED}Executable not found: {PUSH_SWAP_EXEC}{RESET}")
        exit(1)
    
    # Count moves (each line = one operation)
    moves = [line for line in result.stdout.strip().split("\n") if line.strip()]
    moves_count = len(moves)
    
    # Check if numbers are sorted
    final_numbers = list(map(int, result.stdout.strip().split("\n")[-len(numbers):]))
    is_sorted = final_numbers == sorted(final_numbers)
    
    sort_status = f"{GREEN}OK{RESET}" if is_sorted else f"{RED}FAIL{RESET}"
    
    # Check if move count is within limits
    num_count = len(numbers)
    move_limit = limits.get(num_count, None)
    if move_limit is not None:
        moves_status = f"{GREEN}OK{RESET}" if moves_count <= move_limit else f"{RED}FAIL{RESET}"
        moves_info = f"{moves_count} {moves_status}"
    else:
        moves_info = f"{moves_count} N/A"

    # Print results
    print(f"--- {test_file} --- Numbers: {num_count} | Sort: {sort_status} | Moves: {moves_info}")
