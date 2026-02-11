# Push Swap

A sorting algorithm project that sorts data on a stack with a limited set of instructions, using the lowest possible number of actions.

## 📋 Table of Contents

- [Overview](#overview)
- [The Challenge](#the-challenge)
- [Stack Operations](#stack-operations)
- [Algorithm](#algorithm)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Performance](#performance)
- [Author](#author)

## 🎯 Overview

Push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers in ascending order using two stacks (a and b) and a limited set of operations, while minimizing the number of moves.

The program takes a list of integers as arguments and outputs the most efficient sequence of operations to sort them.

## 🎮 The Challenge

### Rules

- You have 2 stacks named **a** and **b**
- Stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated
- Stack **b** is empty at the start
- The goal is to sort numbers in stack **a** in ascending order
- You can only use the following operations

### Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack a |
| `sb` | Swap the first 2 elements at the top of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Take the first element at the top of b and put it at the top of a |
| `pb` | Take the first element at the top of a and put it at the top of b |
| `ra` | Rotate stack a upward (first element becomes last) |
| `rb` | Rotate stack b upward (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate a (last element becomes first) |
| `rrb` | Reverse rotate b (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## 🧠 Algorithm

The program implements an optimized sorting algorithm that adapts based on the input size:

### Small Sorts (2-5 elements)

- **2 elements**: Simple swap if needed
- **3 elements**: Hardcoded optimal solution (maximum 2 operations)
- **4-5 elements**: Push smallest elements to stack b, sort remaining in a, push back

### Large Sorts (6+ elements) - Turkish Algorithm

The implementation uses an optimized "Turkish Algorithm" approach:

1. **Indexing**: Convert values to ranks/indices (0 to n-1)
2. **Push to B**: Push all but 3 elements to stack b
3. **Sort Three**: Sort the remaining 3 elements in stack a
4. **Optimize Push Back**: 
   - Calculate target position in stack a for each element in stack b
   - Calculate rotation costs for both stacks
   - Choose and execute the cheapest move
   - Repeat until stack b is empty
5. **Final Rotation**: Rotate stack a to position the minimum at the top

#### Cost Calculation

For each element in stack b:
- Calculate how many rotations needed in stack a to reach target position
- Calculate how many rotations needed in stack b to bring element to top
- Consider both directions (rotate vs reverse rotate)
- Optimize by using simultaneous rotations (rr/rrr) when both stacks rotate in same direction

## 🚀 Installation

### Prerequisites

- GCC or Clang compiler
- Make
- Libft library (should be in the `libft/` directory)

### Build

```bash
# Clone the repository
git clone https://github.com/grace-hdd/push_swap.git
cd push_swap

# Compile the project
make

# Clean object files
make clean

# Remove all compiled files
make fclean

# Recompile everything
make re
```

## 💻 Usage

```bash
./push_swap [list of integers]
```

### Input Formats

The program accepts integers in two formats:

1. **Multiple arguments**:
```bash
./push_swap 2 1 3 6 5 8
```

2. **Single quoted string**:
```bash
./push_swap "2 1 3 6 5 8"
```

### Output

The program outputs the sequence of operations needed to sort the stack:

```bash
./push_swap 2 1 3
sa
rra
```

### Error Handling

The program outputs `Error` to stderr and exits with status 1 if:
- Arguments are not integers
- Arguments exceed INT_MAX or INT_MIN
- There are duplicate numbers
- Invalid format

## 📚 Examples

### Example 1: Sort 3 numbers

```bash
$ ./push_swap 2 1 3
sa
```

### Example 2: Sort 5 numbers

```bash
$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
```

### Example 3: Already sorted

```bash
$ ./push_swap 1 2 3 4 5
# No output - already sorted
```

### Example 4: Testing with random numbers

```bash
# Generate random test
$ ARG=$(shuf -i 1-100 -n 10 | tr '\n' ' '); echo $ARG
$ ./push_swap $ARG | wc -l  # Count operations
```

### Example 5: Error cases

```bash
$ ./push_swap 1 2 2 3
Error

$ ./push_swap 1 2 abc
Error

$ ./push_swap 1 2147483648
Error
```

## 📁 Project Structure

```
push_swap/
├── push_swap.h           # Header file with structures and function prototypes
├── main.c                # Entry point, parsing, and stack initialization
├── Makefile              # Build configuration
├── libft/                # Custom C library
│
├── Parsing & Validation:
│   ├── parsing.c         # Argument parsing logic
│   ├── validation.c      # Input validation (duplicates, format)
│   └── error.c           # Error handling
│
├── Stack Operations:
│   ├── stack.c           # Stack initialization and management
│   ├── stack_utils.c     # Stack utility functions
│   ├── push.c            # Push operations (pa, pb)
│   ├── swap.c            # Swap operations (sa, sb, ss)
│   ├── rotate.c          # Rotate operations (ra, rb, rr)
│   └── reverse_rotate.c  # Reverse rotate operations (rra, rrb, rrr)
│
├── Sorting Algorithms:
│   ├── sort_small.c      # Sorting for 2-5 elements
│   ├── sort_large.c      # Turkish algorithm for large arrays
│   ├── sort_utils.c      # Sorting helper functions
│   ├── cost.c            # Cost calculation for moves
│   ├── target.c          # Target position calculation
│   └── helpers.c         # Additional helper functions
│
└── Utils:
    └── utils.c           # General utility functions
```

## 📊 Performance

The algorithm achieves optimal performance for various input sizes:

| Elements | Max Operations (42 Requirements) | Typical Performance |
|----------|----------------------------------|---------------------|
| 3        | 3                                | 0-2                 |
| 5        | 12                               | 7-12                |
| 100      | 700                              | 500-700             |
| 500      | 5500                             | 3500-5500           |

## 🔍 Key Features

- **Memory Safe**: Proper allocation and deallocation of all resources
- **Error Handling**: Comprehensive input validation
- **Optimized Algorithm**: Uses cost-based optimization for large datasets
- **Norminette Compliant**: Follows 42 coding standards
- **No Memory Leaks**: Tested with valgrind

## 🧪 Testing

You can test the program with various tools:

```bash
# Test with 100 random numbers
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# Verify the output sorts correctly (requires checker program)
./push_swap $ARG | ./checker_linux $ARG

# Test for memory leaks
valgrind --leak-check=full ./push_swap 3 2 1 5 4
```

## 🛠️ Technical Details

### Data Structures

- **t_node**: Doubly linked list node containing value, index, target position, and costs
- **t_stack**: Stack structure with pointers to top, bottom, and size counter

### Algorithm Complexity

- **Time Complexity**: O(n²) in worst case, but optimized for practical performance
- **Space Complexity**: O(n) for the two stacks

## 📝 Notes

- The program uses index compression to work with ranks instead of actual values
- All operations are printed to stdout
- The program is designed for efficiency, not just correctness
- Stack a always maintains the ascending order requirement (top to bottom)

## 👤 Author

**Grace Haddad**
- GitHub: [@grace-hdd](https://github.com/grace-hdd)
- Email: grhaddad@student.42beirut.com

## 📄 License

This project is part of the 42 curriculum.

---

Made with ☕ at 42 Beirut
