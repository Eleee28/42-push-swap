<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/push_swapm.png" alt="push swap badge">
</p>

<h1 align="center">
  42 Push Swap
</h1>

<!-- # 42_push_swap -->

Statement of the project (in [Spanish](es.subject.pdf) / [English](en.subject.pdf))

## Introduction

This project is a sorting algorithm challenge. The goal is to sort a list of integers using a specific set of operations on two stacks. The project tests your ability to implement efficient sorting algorithms and manage data structures.

## Project Objectives

- Implement sorting algorithms using two stacks.

- Optimize the sorting process to minimize the number of operations.

- Ensure the implementation can handle various edge cases and large inputs efficiently.

## Stack Operations

You have two stacks, named '**a**' and '**b**'. The operations you can use to manipulate these stack are:

### Swap

- '**sa**': Swap the first two elements at the top of stack '**a**'.

- '**sb**': Swap the first two elements at the top of stack '**b**'.

- '**ss**': '**sa**' and '**sb**' at the same time.

### Push

- '**pa**': Take the first element at the top of '**b**' and put it at the top of '**a**'.

- '**pb**': Take the first element at the top of '**a**' and put it at the top of '**b**'.

### Rotate

- '**ra**': Shift all elements of stack '**a**' up by one. The first element becomes the last one.

- '**rb**': Shift all elements of stack '**b**' up by one. The first element becomes the last one.

- '**rr**': '**ra**' and '**rb**' at the same time.

### Reverse Rotate

- '**rra**': Shift all elements of stack '**a**' down by one. The last element becomes the first one.

- '**rrb**': Shift all elements of stack '**b**' down by one. The last element becomes the first one.

- '**rrr**': '**rra**' and '**rrb**' at the same time.

## Mandatory Part

### Program

You must write a program named '**push_swap**' which will receive as argument the list of integers to be sorted. The program must display the list of operations to sort the integers.

```sh
./push_swap 3 2 1
```

The output should be a list of operations:

```sh
pb
pb
sa
pa
pa
```

### Constraints

- You are allowed to use only the operations listed above.

- Your program should sort the integers in ascending order.

- The goal is to minimize the number of operations.

- The input integers are unique.

### Error Handling

- The program should handle errors, such as non-integer input or duplicate numbers, and display an appropiate error message.

## Bonus Part

### Checker Program

Write a program names '**checker**' that takes the same arguments as '**push_swap**' and reads the operations from standard input. After executing the operations, the program should check if the list is sorted.

```sh
./checker 1 3 2
```

You can then type the operations:

```sh
pb
sa
pb
```

The program will output:

```sh
OK
```

If the operations do not sort the list, it will output:

```sh
KO
```

### Advanced Algorithms

Implement more efficient sorting algorithms to handle larger inputs with fewer operations. The efficiency of the algorithm will be tested with different sizes of input lists.

## Implementation

1. **Parsing Input**: Parse the input arguments and validate them. Ensure they are all integers and there are no duplicates.

2. **Initialize Stacks**: Create and initialize the two stacks '**a**' and '**b**'.

3. **Sorting Algorithm**: Implement a sorting algorithm using the allowed operations to sort the integers in stack '**a**'.

4. **Output Operations**: Print the list of operations that will sort the integers.

5. **Bonus** - **Checker Program**: Implement the checker program to validate the sorting operations.
