# `push_swap`

![42 school project](https://img.shields.io/badge/42-Project-4285F4?style=for-the-badge&logo=42)

---

## Introduction

This project is a key part of the **42 school curriculum**. The goal of `push_swap` is to sort a list of integers using the smallest number of operations possible. The challenge is to sort a stack, `a`, into ascending order using a limited set of instructions and a second, empty stack, `b`.

The available instructions are:
-   **`sa`**: swap the first two elements of stack `a`.
-   **`sb`**: swap the first two elements of stack `b`.
-   **`ss`**: `sa` and `sb` at the same time.
-   **`pa`**: push the top element of `b` to `a`.
-   **`pb`**: push the top element of `a` to `b`.
-   **`ra`**: rotate `a` (the first element becomes the last).
-   **`rb`**: rotate `b` (the first element becomes the last).
-   **`rr`**: `ra` and `rb` at the same time.
-   **`rra`**: reverse rotate `a` (the last element becomes the first).
-   **`rrb`**: reverse rotate `b` (the last element becomes the first).
-   **`rrr`**: `rra` and `rrb` at the same time.

---

## How It Works: The Turk Algorithm

My `push_swap` implementation uses the **Turk algorithm**, which is a widely-used strategy for this project. The main idea is to move chunks of stack `a` to stack `b` in a controlled manner, and then efficiently move them back to `a` in their correct sorted positions.

The process can be broken down into these main steps:

1.  **Initial Push**: A small number of elements are left in stack `a` (e.g., the 3 smallest elements) while the rest are pushed to stack `b`.
2.  **Cost Calculation**: For each element in stack `b`, the algorithm calculates the "cost" to move it back to stack `a`. The cost is the minimum number of rotations (`ra`, `rb`, `rra`, `rrb`) and pushes (`pa`) required to place it at its correct sorted position in `a`.
3.  **Optimal Move**: The element in `b` with the lowest cost is chosen. The calculated rotations are performed on both stacks simultaneously where possible (`rr`, `rrr`), and then the element is pushed back to `a` using `pa`.
4.  **Repeat**: This process of cost calculation and moving the cheapest element is repeated until stack `b` is empty.
5.  **Final Sort**: Once all elements are back in stack `a`, the stack is nearly sorted. A final series of `ra` or `rra` operations is performed to place the smallest element at the top, completing the sort.

---

## Installation and Usage

To compile and run `push_swap`, you will need a `Makefile`.

### Compilation

You can compile your program using the provided `Makefile`.

```bash
make
```

### Running the Program

The program takes a list of integers as arguments.

```bash
./push_swap 2 1 3 6 5 4
```

---

## Bonus: `checker`

The bonus part of this project is a program called `checker`. It reads a list of integers from the command line and then reads a series of instructions from standard input. It then executes the instructions on the stack and prints "OK" if the stack is sorted correctly, or "KO" if it is not.

You can use it to verify the output of your `push_swap` program by piping the output of `push_swap` to `checker`.

```bash
./push_swap 2 1 3 6 5 4 | ./checker 2 1 3 6 5 4
```

---

## Project Contributor

-   **Ruben Finnerud** - [rubenfin](https://github.com/rubenfin)

---

