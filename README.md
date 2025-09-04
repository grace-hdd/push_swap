# Push Swap

A 42 School project that implements an efficient sorting algorithm using two stacks and a limited set of operations.

## 📋 Table of Contents

- [Overview](#overview)
- [Algorithm](#algorithm)
- [Operations](#operations)
- [Installation](#installation)
- [Usage](#usage)
- [Performance](#performance)
- [Project Structure](#project-structure)
- [Testing](#testing)
- [Contributing](#contributing)

## 🎯 Overview

Push Swap is a sorting algorithm project that demonstrates efficient data manipulation using two stacks (A and B) with a restricted set of operations. The goal is to sort a list of integers using the minimum number of operations possible.

### Key Features

- **Three-tier sorting strategy**: Different algorithms for different stack sizes
- **Optimized operations**: Minimizes the number of moves required
- **42 norminette compliant**: Follows strict coding standards
- **Memory efficient**: Proper memory management and cleanup
- **Error handling**: Comprehensive input validation and error management

## 🧮 Algorithm

The project implements a multi-strategy approach based on stack size:

### Small Stacks (≤ 3 elements)
- **Direct sorting**: Uses pattern recognition for optimal sorting
- **Cases handled**: All 6 possible permutations of 3 elements
- **Operations**: 0-2 operations maximum

### Medium Stacks (4-5 elements)
- **Hybrid approach**: Pushes smallest elements to stack B, sorts remaining 3, then merges
- **Strategy**: Find minimum values, push to B, sort A with 3-element algorithm, merge back
- **Operations**: Typically 4-7 operations

### Large Stacks (> 5 elements)
- **Chunk-based sorting**: Divides stack into optimal chunks
- **Dynamic chunk sizing**: Adapts chunk size based on stack size
- **Median-based partitioning**: Uses median values for efficient chunking
- **Operations**: Scales logarithmically with stack size

## 🔧 Operations

The algorithm uses 11 different operations:

### Stack Operations
- `sa` - Swap first two elements of stack A
- `sb` - Swap first two elements of stack B
- `ss` - Swap first two elements of both stacks

### Push Operations
- `pa` - Push first element from B to A
- `pb` - Push first element from A to B

### Rotate Operations
- `ra` - Rotate stack A (first element becomes last)
- `rb` - Rotate stack B (first element becomes last)
- `rr` - Rotate both stacks

### Reverse Rotate Operations
- `rra` - Reverse rotate stack A (last element becomes first)
- `rrb` - Reverse rotate stack B (last element becomes first)
- `rrr` - Reverse rotate both stacks

## 🚀 Installation

### Prerequisites
- GCC compiler
- Make
- libft library (42 School standard library)

### Setup
1. Clone the repository:
```bash
git clone <repository-url>
cd push_swap
```

2. Ensure libft is available:
```bash
# libft should be in the parent directory or adjust the path in Makefile
ls ../libft/
```

3. Compile the project:
```bash
make
```

## 💻 Usage

### Basic Usage
```bash
./push_swap [numbers...]
```

### Examples
```bash
# Sort 3 numbers
./push_swap 3 1 2

# Sort 5 numbers
./push_swap 5 2 1 4 3

# Sort 100 numbers
./push_swap $(seq 1 100 | shuf)
```

### With Checker (if available)
```bash
# Generate random numbers and test
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## 📊 Performance

### Operation Counts
- **3 elements**: 0-2 operations
- **5 elements**: 4-7 operations
- **100 elements**: < 700 operations
- **500 elements**: < 5500 operations

### Time Complexity
- **Small stacks**: O(1) - constant time
- **Medium stacks**: O(n) - linear time
- **Large stacks**: O(n log n) - near-optimal

## 📁 Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h          # Main header file
├── src/
│   ├── main.c               # Entry point
│   ├── algorithm/
│   │   ├── sort_small.c     # 3 & 5 element sorting
│   │   ├── sort_large.c     # Large stack algorithm
│   │   └── algorithm_utils.c # Helper functions
│   ├── operations/
│   │   ├── swap.c           # sa, sb, ss operations
│   │   ├── push.c           # pa, pb operations
│   │   ├── rotate.c         # ra, rb, rr operations
│   │   └── reverse_rotate.c # rra, rrb, rrr operations
│   ├── parsing/
│   │   ├── parsing_input.c  # Input parsing
│   │   └── validate_input.c # Input validation
│   ├── stack/
│   │   ├── stack_init.c     # Stack initialization
│   │   ├── stack_operations.c # Basic stack operations
│   │   └── stack_utils.c    # Stack utilities
│   └── utils/
│       ├── error_handling.c # Error management
│       └── print_operations.c # Operation printing
├── Makefile                 # Build configuration
└── README.md               # This file
```

## 🧪 Testing

### Manual Testing
```bash
# Test with different sizes
./push_swap 1 2 3
./push_swap 3 1 2
./push_swap 5 4 3 2 1
```

### Performance Testing
```bash
# Test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Memory Testing
```bash
# Check for memory leaks
valgrind --leak-check=full ./push_swap 3 1 2
```

## 🎯 Algorithm Details

### Small Stack Sorting (3 elements)
The algorithm recognizes all 6 possible patterns:
- `123` - Already sorted (0 operations)
- `132` - sa, rra (2 operations)
- `213` - sa (1 operation)
- `231` - rra (1 operation)
- `312` - ra (1 operation)
- `321` - rra (1 operation)

### Large Stack Sorting
1. **Chunk Calculation**: Determines optimal chunk size based on stack size
2. **Median Finding**: Calculates median for each chunk
3. **Chunk Processing**: Pushes elements ≤ median to stack B
4. **Rotation Optimization**: Chooses between ra/rra for minimum operations
5. **Merge Phase**: Sorts stack B and merges back to stack A

## 🔍 Error Handling

The program handles various error conditions:
- Invalid input format
- Duplicate numbers
- Numbers outside integer range
- Memory allocation failures
- Empty input

## 📈 Optimization Strategies

1. **Operation Minimization**: Always chooses the shortest path
2. **Smart Rotations**: Prefers ra over rra when equal distance
3. **Chunk Optimization**: Dynamic chunk sizing for different stack sizes
4. **Pattern Recognition**: Direct handling of common patterns

## 🏆 Achievements

- ✅ 42 norminette compliant
- ✅ Memory leak free
- ✅ Handles all edge cases
- ✅ Optimized for performance
- ✅ Clean, readable code structure

## 📝 Notes

- The project uses the 42 School libft library
- All operations are printed to stdout
- The program exits with appropriate error codes
- Memory is properly managed and freed

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on how to contribute to this project.

## 📄 License

This project is part of the 42 School curriculum and follows the school's academic integrity policies.