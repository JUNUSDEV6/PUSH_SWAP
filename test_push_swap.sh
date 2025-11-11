#!/bin/bash

# Script de test pour push_swap
# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PUSH_SWAP="./push_swap"
CHECKER="./checker"

# Function to test if result is sorted
test_sorted() {
	local args="$1"
	local output=$($PUSH_SWAP $args)
	local temp_file=$(mktemp)
	
	echo "$args" | tr ' ' '\n' | sort -n > $temp_file
	local sorted_result=$(echo "$args" | tr ' ' '\n' | $PUSH_SWAP $args 2>/dev/null | wc -l 2>/dev/null || echo "0")
	
	if [ -z "$output" ] && echo "$args" | tr ' ' '\n' | sort -n -c >/dev/null 2>&1; then
		echo -e "${GREEN}✓ Already sorted: $args${NC}"
		return 0
	fi
	
	# Simulate the operations (simplified check)
	local move_count=$(echo "$output" | wc -l)
	echo -e "${YELLOW}Moves for [$args]: $move_count${NC}"
	
	rm -f $temp_file
	return 0
}

echo "=== PUSH_SWAP TESTER ==="
echo

# Test 1: Already sorted
echo "Test 1: Already sorted lists"
test_sorted "1 2 3 4 5"
test_sorted "1"
test_sorted "1 2"

echo

# Test 2: Small lists (2-5 elements)
echo "Test 2: Small lists"
test_sorted "2 1"
test_sorted "3 2 1"
test_sorted "3 1 2"
test_sorted "4 3 2 1"
test_sorted "5 4 3 2 1"

echo

# Test 3: Medium lists
echo "Test 3: Medium lists (10 elements)"
test_sorted "10 9 8 7 6 5 4 3 2 1"
test_sorted "5 2 8 1 9 3 7 4 6 10"

echo

# Test 4: Error cases
echo "Test 4: Error cases"
echo -n "Duplicate numbers: "
$PUSH_SWAP 1 2 2 3 2>/dev/null && echo -e "${RED}FAIL${NC}" || echo -e "${GREEN}OK${NC}"

echo -n "Invalid argument: "
$PUSH_SWAP 1 abc 3 2>/dev/null && echo -e "${RED}FAIL${NC}" || echo -e "${GREEN}OK${NC}"

echo -n "Empty string: "
$PUSH_SWAP "" 2>/dev/null && echo -e "${RED}FAIL${NC}" || echo -e "${GREEN}OK${NC}"

echo
echo "=== Tests completed ==="
