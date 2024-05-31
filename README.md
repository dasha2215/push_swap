# Push_swap

## Overview

**Push_swap** is a project designed to sort a stack of integers using a limited set of stack operations with the minimum number of moves possible. The goal is to write a program in C that outputs the shortest possible sequence of operations to sort the given stack of integers. This project helps in understanding and implementing sorting algorithms while focusing on minimizing the number of operations.

## Objectives

- The algorithm must be able to sort **100** random numbers in fewer than **700** operations.
- For **500** random numbers, there should be no more than **5500** operations.

## Instructions

- The project involves two stacks, `a` and `b`.
- The goal is to sort stack `a` in ascending order using the following operations:
  - `sa`: Swap the first two elements of stack `a`.
  - `sb`: Swap the first two elements of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the first element from stack `b` to stack `a`.
  - `pb`: Push the first element from stack `a` to stack `b`.
  - `ra`: Rotate stack `a` upwards.
  - `rb`: Rotate stack `b` upwards.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Rotate stack `a` downwards.
  - `rrb`: Rotate stack `b` downwards.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

## Sorting Algorithm

For sorting large sets of numbers (100 to 500), the project uses a three-way quick sort algorithm inspired by Ulysse Gerkens. This algorithm effectively reduces the problem size and improves sorting efficiency by dividing the stack into three parts using two pivot values.

**The average number of operations for sorting 500 random numbers is 4200.**

### Three-way Quick Sort Steps

1. **Choose Pivots**: Select two pivot values to divide the stack into three roughly equal parts.
2. **Partitioning**: 
   - Elements less than the first pivot go to one part.
   - Elements between the two pivots go to another part.
   - Elements greater than the second pivot go to the third part.
3. **Recursion**: Recursively apply the same logic to each partition until the base cases (1, 2, or 3 elements) are reached.
4. **Optimized Handling**: Handle smaller chunks (less than 10 elements) with simpler algorithms to optimize performance.

For more details, refer to the article by Ulysse Gerkens: ["Push_swap in less than 4200 operations"](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0).

## File Structure

- **Source Files**: `*.c` - Implementation of the algorithm and operations.
- **Header Files**: `*.h` - Function declarations and data structures.
- **Makefile**: Automates the compilation process.

## Compilation and Execution

To compile the project, use the provided Makefile:

```sh
make
```

To run the program with a set of integers:

```sh
./push_swap 2 1 3 6 5 8
```

### Error Handling

The program handles the following errors gracefully:

- **Non-integer inputs**: The program checks if the inputs are valid integers.
- **Integer overflows**: The program ensures that the input values are within the valid range for integers.
- **Duplicate values**: The program checks for and rejects duplicate integers.
- **Invalid operations**: The program detects and handles invalid operations, ensuring that only valid commands are executed.

In case of an error, the program displays "Error" followed by a newline on the standard error output and exits.

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
