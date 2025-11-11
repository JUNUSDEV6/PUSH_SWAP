#!/bin/bash

# Benchmark script pour push_swap
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

PUSH_SWAP="./push_swap"
CHECKER="./checker"

echo -e "${BLUE}=== PUSH_SWAP BENCHMARK ===${NC}"
echo

# Function to generate random numbers
generate_numbers() {
	local count=$1
	python3 -c "import random; print(' '.join(map(str, random.sample(range(1, $((count * 10))), $count))))"
}

# Function to test performance
benchmark() {
	local size=$1
	local iterations=$2
	local total_moves=0
	local max_moves=0
	local min_moves=999999

	echo -e "${YELLOW}Testing $size numbers ($iterations iterations):${NC}"
	
	for ((i=1; i<=iterations; i++)); do
		local numbers=$(generate_numbers $size)
		local moves=$($PUSH_SWAP $numbers | wc -l)
		
		# Verify correctness
		local result=$($PUSH_SWAP $numbers | $CHECKER $numbers)
		if [ "$result" != "OK" ]; then
			echo -e "${RED}Error: Algorithm failed for: $numbers${NC}"
			return 1
		fi
		
		total_moves=$((total_moves + moves))
		
		if [ $moves -gt $max_moves ]; then
			max_moves=$moves
		fi
		
		if [ $moves -lt $min_moves ]; then
			min_moves=$moves
		fi
		
		printf "\r  Progress: %d/%d" $i $iterations
	done
	
	local avg_moves=$((total_moves / iterations))
	
	echo
	echo -e "  Average moves: ${GREEN}$avg_moves${NC}"
	echo -e "  Min moves: ${GREEN}$min_moves${NC}"
	echo -e "  Max moves: ${GREEN}$max_moves${NC}"
	
	# 42 School limits
	case $size in
		3)
			if [ $max_moves -le 3 ]; then
				echo -e "  ${GREEN}✓ Passed (≤3 moves)${NC}"
			else
				echo -e "  ${RED}✗ Failed (>3 moves)${NC}"
			fi
			;;
		5)
			if [ $max_moves -le 12 ]; then
				echo -e "  ${GREEN}✓ Passed (≤12 moves)${NC}"
			else
				echo -e "  ${RED}✗ Failed (>12 moves)${NC}"
			fi
			;;
		100)
			if [ $avg_moves -le 700 ]; then
				echo -e "  ${GREEN}✓ Excellent (≤700 moves avg)${NC}"
			elif [ $avg_moves -le 900 ]; then
				echo -e "  ${YELLOW}✓ Good (≤900 moves avg)${NC}"
			elif [ $avg_moves -le 1100 ]; then
				echo -e "  ${YELLOW}○ Average (≤1100 moves avg)${NC}"
			elif [ $avg_moves -le 1300 ]; then
				echo -e "  ${RED}△ Poor (≤1300 moves avg)${NC}"
			else
				echo -e "  ${RED}✗ Failed (>1300 moves avg)${NC}"
			fi
			;;
		500)
			if [ $avg_moves -le 5500 ]; then
				echo -e "  ${GREEN}✓ Excellent (≤5500 moves avg)${NC}"
			elif [ $avg_moves -le 7000 ]; then
				echo -e "  ${YELLOW}✓ Good (≤7000 moves avg)${NC}"
			elif [ $avg_moves -le 8500 ]; then
				echo -e "  ${YELLOW}○ Average (≤8500 moves avg)${NC}"
			elif [ $avg_moves -le 10000 ]; then
				echo -e "  ${RED}△ Poor (≤10000 moves avg)${NC}"
			else
				echo -e "  ${RED}✗ Failed (>10000 moves avg)${NC}"
			fi
			;;
	esac
	
	echo
}

# Run benchmarks
benchmark 3 100
benchmark 5 100
benchmark 100 10
benchmark 500 3

echo -e "${BLUE}=== Benchmark completed ===${NC}"
