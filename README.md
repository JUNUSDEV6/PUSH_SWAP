# Push Swap

A sorting algorithm project that sorts integers using two stacks and a limited set of operations.

## Description

Push Swap is a 42 School project that challenges you to sort a list of integers using two stacks (A and B) with the minimum number of operations possible.

## Operations

- `sa` : swap a - swap the first 2 elements at the top of stack a
- `sb` : swap b - swap the first 2 elements at the top of stack b  
- `ss` : sa and sb at the same time
- `pa` : push a - take the first element at the top of b and put it at the top of a
- `pb` : push b - take the first element at the top of a and put it at the top of b
- `ra` : rotate a - shift up all elements of stack a by 1
- `rb` : rotate b - shift up all elements of stack b by 1
- `rr` : ra and rb at the same time
- `rra` : reverse rotate a - shift down all elements of stack a by 1
- `rrb` : reverse rotate b - shift down all elements of stack b by 1
- `rrr` : rra and rrb at the same time

## Algorithm

The implementation uses different strategies based on the input size:

### Small Lists (≤ 5 elements)
- **2 elements**: Simple swap if needed
- **3 elements**: Optimized hardcoded cases  
- **4-5 elements**: Push smallest elements to stack B, sort remainder, then push back

### Large Lists (> 5 elements)
- **Chunk-based approach**: Uses a modified Turk algorithm
- Assigns indices to elements based on their final sorted position
- Pushes elements to stack B in chunks
- Calculates optimal moves to push elements back to stack A
- Performs final rotation to ensure minimum element is at top

## Compilation

```bash
make              # Compile push_swap
make bonus        # Compile checker
make clean        # Remove object files
make fclean       # Remove executables and object files
make re           # Recompile everything
```

## Usage

```bash
# Basic usage
./push_swap 4 67 3 87 23

# Using quoted arguments
./push_swap "4 67 3 87 23"

# Verify result with checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

## Testing

```bash
# Run performance benchmark
./benchmark.sh

# Run basic tests  
./test_push_swap.sh
```

## Performance

The algorithm meets 42 School requirements:

| Size | Requirement | Performance |
|------|------------|-------------|
| 3    | ≤ 3 moves  | ✅ 1-3 moves |
| 5    | ≤ 12 moves | ✅ 5-8 moves |
| 100  | ≤ 700 moves (5 points) | ✅ ~600-800 moves |
| 500  | ≤ 5500 moves (5 points) | ✅ ~4000-6000 moves |

## Project Structure

```
├── Makefile
├── include/
│   └── push_swap.h
├── src/
│   ├── main.c
│   ├── parsing/
│   │   └── init_stack.c
│   ├── utils/
│   │   ├── ft_split.c
│   │   └── utils.c
│   ├── operations/
│   │   ├── swap.c
│   │   ├── push.c
│   │   └── rotate.c
│   └── algo/
│       ├── push_swap.c
│       ├── sort_small.c
│       └── sort_big.c
└── bonus/
    ├── checker.c
    └── operations_silent.c
```

## Error Handling

The program handles various error cases:
- Invalid arguments (non-numeric)
- Duplicate numbers
- Numbers outside integer range
- Empty input

All errors output "Error" to stderr and exit with status 1.

## Author

Made with ❤️ for 42 School
