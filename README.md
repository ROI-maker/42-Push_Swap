<!--HEADER-->
<h1 align="center"> Push_swap | 
  <picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://cdn.simpleicons.org/42/white">
  <img alt="42" width=40 align="center" src="https://cdn.simpleicons.org/42/Black">
 </picture>
 Cursus 
  <img alt="Complete" src="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/dark-theme/complete.svg">
</h1>
<!--FINISH HEADER-->

### What is the project about

Push_Swap is a project that challenges you to sort a list of integers using only two stacks and a limited set of operations.  

The goal is not just to sort the numbers, but to do it with the minimum number of instructions possible.  
Specifically, the objective is to sort **100 numbers in fewer than 700 operations** and **500 numbers in fewer than 5500 operations**.  

This project emphasizes algorithmic thinking, efficiency,  
and mastering low-level data manipulation in C.

## General Instructions
* The `Makefile` will compile your source files. It must include an `all` rule for the mandatory part. Relinking should be avoided.
* The program should be compiled and executed using the following command:  

```shell
> make
> ./push_swap 4 67 3 87 23
```

> [!WARNING]
All input numbers must be integers without duplicates.

## Mandatory Instructions
* The program must display the **sequence of operations** used to sort the stack.
* Only integers without duplicates are allowed as input.
* The goal is to sort the stack using the **minimum number of moves**.
* All operations must be valid and adhere to the allowed set:

| Operation | Description                              |
|-----------|------------------------------------------|
| `sa`      | Swap the first two elements of stack A   |
| `sb`      | Swap the first two elements of stack B   |
| `ss`      | `sa` and `sb` at the same time           |
| `pa`      | Push the first element of stack B to A   |
| `pb`      | Push the first element of stack A to B   |
| `ra`      | Rotate stack A upwards (first element → last) |
| `rb`      | Rotate stack B upwards                     |
| `rr`      | `ra` and `rb` at the same time           |
| `rra`     | Reverse rotate stack A (last element → first) |
| `rrb`     | Reverse rotate stack B                     |
| `rrr`     | `rra` and `rrb` at the same time         |

 
## Examples / How it works

**Input:**  
```bash
./push_swap 3 2 1

sa
rra

