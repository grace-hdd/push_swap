# Push Swap Project

## Overview
The Push Swap project is a sorting algorithm that uses two stacks to sort a list of integers. The goal is to sort the numbers in ascending order using a minimal number of operations. This project is designed to demonstrate the implementation of sorting algorithms and stack manipulation techniques.

## Project Structure
```
push_swap
├── src
│   ├── main.c
│   ├── push_swap.c
│   ├── stack.c
│   ├── operations.c
│   └── utils.c
├── include
│   └── push_swap.h
├── Makefile
└── README.md
```

## Files Description

- **src/main.c**: Entry point of the application. Initializes the program, processes input arguments, and calls the main logic of the push_swap algorithm.

- **src/push_swap.c**: Contains the implementation of the push_swap algorithm, including functions to sort the stack and manage the operations required to achieve the sorted order.

- **src/stack.c**: Defines the stack data structure and related functions, including operations for stack manipulation such as push, pop, and checking if the stack is empty.

- **src/operations.c**: Implements various operations that can be performed on the stacks, such as swap, rotate, and reverse rotate.

- **src/utils.c**: Contains utility functions that assist with the main algorithm, including error handling, input validation, and helper functions for managing the stacks.

- **include/push_swap.h**: Header file containing declarations of functions and structures used in the push_swap project, along with necessary includes and constants.

- **Makefile**: Used to compile the project, defining rules for building the executable, including source files and compiler options.

## Building the Project
To build the project, navigate to the root directory of the project and run the following command:

```
make
```

This will compile the source files and create the executable.

## Running the Project
After building the project, you can run the executable with the following command:

```
./push_swap [list of integers]
```

Replace `[list of integers]` with the integers you want to sort. The program will output the sequence of operations needed to sort the numbers.

## Example Usage
```
./push_swap 3 2 1
```

This command will sort the numbers 3, 2, and 1 using the push_swap algorithm and display the operations performed.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.