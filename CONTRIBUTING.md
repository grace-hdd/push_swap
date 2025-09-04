# Contributing to Push Swap

Thank you for your interest in contributing to the Push Swap project! This guide will help you understand the project structure, coding standards, and how to make meaningful contributions.

## 📋 Table of Contents

- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Coding Standards](#coding-standards)
- [Development Workflow](#development-workflow)
- [Testing Guidelines](#testing-guidelines)
- [Code Review Process](#code-review-process)
- [Common Issues](#common-issues)
- [Performance Guidelines](#performance-guidelines)

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- 42 School libft library
- Git
- Basic understanding of C programming
- Familiarity with 42 School coding standards

### Setting Up Development Environment

1. **Fork and Clone**
```bash
git clone <your-fork-url>
cd push_swap
```

2. **Set up libft**
```bash
# Ensure libft is in the correct location
ls ../libft/
# If not present, clone libft
git clone https://github.com/42School/libft.git ../libft
```

3. **Compile and Test**
```bash
make
./push_swap 3 1 2
```

## 📁 Project Structure

Understanding the project structure is crucial for effective contributions:

```
push_swap/
├── includes/
│   └── push_swap.h          # Main header - add new function declarations here
├── src/
│   ├── main.c               # Entry point - minimal changes needed
│   ├── algorithm/           # Core sorting algorithms
│   │   ├── sort_small.c     # 3 & 5 element sorting
│   │   ├── sort_large.c     # Large stack algorithm
│   │   └── algorithm_utils.c # Helper functions for algorithms
│   ├── operations/          # Stack operations implementation
│   │   ├── swap.c           # sa, sb, ss
│   │   ├── push.c           # pa, pb
│   │   ├── rotate.c         # ra, rb, rr
│   │   └── reverse_rotate.c # rra, rrb, rrr
│   ├── parsing/             # Input handling
│   │   ├── parsing_input.c  # Parse command line arguments
│   │   └── validate_input.c # Validate input data
│   ├── stack/               # Stack data structure
│   │   ├── stack_init.c     # Stack creation/destruction
│   │   ├── stack_operations.c # Basic stack operations
│   │   └── stack_utils.c    # Stack utility functions
│   └── utils/               # General utilities
│       ├── error_handling.c # Error management
│       └── print_operations.c # Operation output
└── Makefile                 # Build configuration
```

## 📏 Coding Standards

### 42 Norminette Compliance
All code must follow 42 School's norminette standards:

#### Function Formatting
```c
// ✅ Correct
int	my_function(t_stack *stack, int value)
{
	// function body
}

// ❌ Incorrect
int my_function(t_stack *stack, int value) {
    // function body
}
```

#### Variable Declarations
```c
// ✅ Correct
int		i;
t_node	*current;
char	*str;

// ❌ Incorrect
int i;
t_node *current;
char *str;
```

#### Line Length and Spacing
- Maximum 80 characters per line
- No more than 4 functions per file
- No more than 25 lines per function
- Proper indentation with tabs (not spaces)

#### Header Guards
```c
// ✅ Correct
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// content
#endif
```

### Naming Conventions
- **Functions**: `snake_case` (e.g., `sort_three`, `find_min`)
- **Variables**: `snake_case` (e.g., `stack_size`, `current_node`)
- **Types**: `t_` prefix (e.g., `t_stack`, `t_node`)
- **Constants**: `UPPER_CASE` (e.g., `MAX_STACK_SIZE`)

### Memory Management
```c
// ✅ Always check malloc return
t_node	*node = malloc(sizeof(t_node));
if (!node)
	return (NULL);

// ✅ Always free allocated memory
free(ptr);
ptr = NULL;
```

## 🔄 Development Workflow

### 1. Creating a Feature Branch
```bash
git checkout -b feature/your-feature-name
# or
git checkout -b fix/issue-description
```

### 2. Making Changes
- Make small, focused commits
- Write descriptive commit messages
- Test your changes thoroughly

### 3. Commit Message Format
```
type: brief description

Detailed explanation of changes made.
- Bullet point for specific changes
- Another bullet point if needed

Fixes #issue-number (if applicable)
```

Types: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`

### 4. Testing Your Changes
```bash
# Compile
make

# Test basic functionality
./push_swap 3 1 2

# Test with different sizes
./push_swap 5 4 3 2 1
./push_swap 1 2 3 4 5

# Check for memory leaks
valgrind --leak-check=full ./push_swap 3 1 2
```

### 5. Code Review Checklist
Before submitting a pull request, ensure:

- [ ] Code follows 42 norminette standards
- [ ] All functions are properly documented
- [ ] Memory is properly managed
- [ ] Error handling is comprehensive
- [ ] Tests pass for various inputs
- [ ] No memory leaks detected
- [ ] Performance is not degraded

## 🧪 Testing Guidelines

### Unit Testing
Test individual functions with various inputs:

```c
// Example test for find_min function
void	test_find_min(void)
{
	t_stack	*stack = create_stack();
	
	// Test with empty stack
	assert(find_min(stack) == 0);
	
	// Test with single element
	push(stack, 5);
	assert(find_min(stack) == 5);
	
	// Test with multiple elements
	push(stack, 3);
	push(stack, 7);
	assert(find_min(stack) == 3);
	
	destroy_stack(stack);
}
```

### Integration Testing
Test the complete sorting process:

```bash
# Test all permutations of 3 elements
for i in {1..6}; do
    ./push_swap $(echo "1 2 3" | tr ' ' '\n' | shuf | tr '\n' ' ')
done

# Test with larger inputs
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG
```

### Performance Testing
```bash
# Measure operation count
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Time the execution
time ./push_swap $(seq 1 500 | shuf | tr '\n' ' ')
```

## 🔍 Code Review Process

### What Reviewers Look For

1. **Correctness**
   - Does the code solve the problem?
   - Are edge cases handled?
   - Is the logic sound?

2. **Performance**
   - Is the algorithm efficient?
   - Are there unnecessary operations?
   - Is memory usage optimized?

3. **Code Quality**
   - Is the code readable?
   - Are functions well-named?
   - Is the structure logical?

4. **Standards Compliance**
   - Does it follow 42 norminette?
   - Are comments appropriate?
   - Is documentation complete?

### Common Review Comments

- **"Consider extracting this into a separate function"** - Code is too long or complex
- **"Add error handling for this case"** - Missing error checking
- **"This could be optimized"** - Performance improvement needed
- **"Follow naming convention"** - Incorrect variable/function naming

## 🐛 Common Issues

### Memory Leaks
```c
// ❌ Common mistake
void	bad_function(void)
{
	t_stack	*stack = create_stack();
	// ... use stack ...
	// Forgot to call destroy_stack(stack);
}

// ✅ Correct approach
void	good_function(void)
{
	t_stack	*stack = create_stack();
	if (!stack)
		return ;
	// ... use stack ...
	destroy_stack(stack);
}
```

### Stack Underflow
```c
// ❌ Dangerous
int	value = stack->top->value; // What if stack is empty?

// ✅ Safe
if (is_empty(stack))
	return (0);
int	value = stack->top->value;
```

### Input Validation
```c
// ❌ Missing validation
int	*parse_input(int argc, char **argv, int *count)
{
	// Directly use argv without validation
}

// ✅ Proper validation
int	*parse_input(int argc, char **argv, int *count)
{
	if (argc < 2)
		return (NULL);
	// ... validate each argument ...
}
```

## ⚡ Performance Guidelines

### Algorithm Optimization
- **Minimize operations**: Always choose the shortest path
- **Smart rotations**: Prefer ra over rra when equal distance
- **Chunk optimization**: Use appropriate chunk sizes
- **Pattern recognition**: Handle common cases directly

### Memory Optimization
- **Reuse variables**: Don't create unnecessary temporary variables
- **Efficient data structures**: Use appropriate data types
- **Minimize allocations**: Reduce malloc/free calls

### Code Optimization
- **Avoid redundant calculations**: Cache frequently used values
- **Early returns**: Exit functions as soon as possible
- **Efficient loops**: Minimize loop iterations

## 📚 Learning Resources

### 42 School Resources
- [42 Norminette](https://github.com/42School/norminette)
- [42 Cursus Guidelines](https://github.com/42School/42-cursus)
- [Libft Documentation](https://github.com/42School/libft)

### Algorithm Resources
- [Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [Algorithm Analysis](https://www.khanacademy.org/computing/computer-science/algorithms)

## 🤝 Getting Help

### Before Asking for Help
1. Check existing issues and pull requests
2. Review the code and documentation
3. Test your changes thoroughly
4. Search for similar problems

### How to Ask for Help
1. **Be specific**: Describe exactly what you're trying to do
2. **Provide context**: Include relevant code and error messages
3. **Show your work**: Explain what you've already tried
4. **Be patient**: Allow time for responses

### Communication Channels
- GitHub Issues for bug reports
- GitHub Discussions for questions
- Pull Request comments for code review

## 📝 Documentation

### Code Documentation
- Comment complex algorithms
- Explain non-obvious logic
- Document function parameters and return values
- Include usage examples

### Commit Documentation
- Write clear, descriptive commit messages
- Reference related issues
- Explain the reasoning behind changes

## 🎯 Contribution Ideas

### Algorithm Improvements
- Optimize chunk size calculation
- Implement new sorting strategies
- Add parallel processing support
- Improve rotation optimization

### Code Quality
- Add more comprehensive error handling
- Improve code documentation
- Add performance profiling tools
- Create automated testing suite

### Features
- Add operation counting
- Implement visualization mode
- Create performance benchmarks
- Add configuration options

## 🏆 Recognition

Contributors will be recognized in:
- README.md contributors section
- Release notes
- Project documentation

Thank you for contributing to Push Swap! Your efforts help make this project better for everyone. 🚀
