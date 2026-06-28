 *Este proyecto ha sido creado como parte del currículo de 42 por wlu-bjor, antgarci*

# 🔄 push_swap

![C](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/project-42-purple)

## Description

Sort a list of integers using only two stacks and a limited set of operations. The program selects the most efficient algorithm based on input size and order, then outputs the sequence of operations needed to sort stack `a` from smallest to largest.

## Table of contents

- [Rules & operations](#rules--operations)
- [Sorting strategies](#sorting-strategies)
- [Sortedness index](#sortedness-index)
- [Benchmark mode](#benchmark-mode)
- [Flags](#flags)
- [Usage](#usage)
- [Checker (bonus)](#checker-bonus)
- [Resources](#resources)

---

## Rules & operations

Two stacks are used throughout the program:

- **Stack a** — holds the initial unsorted list of numbers.
- **Stack b** — starts empty and is used as auxiliary storage.

At the end of execution, all numbers must be back in stack `a`, sorted from smallest (top) to largest (bottom). Stack `b` must be empty.

### Available operations

| Operation | Code | Description |
|-----------|------|-------------|
| Swap a | `sa` | Swaps the top two elements of stack a. Does nothing if a has fewer than 2 elements. |
| Swap b | `sb` | Swaps the top two elements of stack b. Does nothing if b has fewer than 2 elements. |
| Swap a & b | `ss` | Applies `sa` and `sb` simultaneously. |
| Push a | `pa` | Moves the top element from stack b to the top of stack a. Does nothing if b is empty. |
| Push b | `pb` | Moves the top element from stack a to the top of stack b. Does nothing if a is empty. |
| Rotate a | `ra` | Shifts all elements of stack a up by one. The top element becomes the last. |
| Rotate b | `rb` | Shifts all elements of stack b up by one. The top element becomes the last. |
| Rotate a & b | `rr` | Applies `ra` and `rb` simultaneously. |
| Reverse rotate a | `rra` | Shifts all elements of stack a down by one. The last element becomes the top. |
| Reverse rotate b | `rrb` | Shifts all elements of stack b down by one. The last element becomes the top. |
| Reverse rotate a & b | `rrr` | Applies `rra` and `rrb` simultaneously. |

---

## Sorting strategies

The program automatically selects the best algorithm based on the input size and sortedness index. You can also force a specific one using flags (see below).

### Simple — Bubble sort `O(n²)`

Repeatedly swaps adjacent elements that are out of order. Best suited for lists of up to ~5 elements where the overhead of complex algorithms isn't justified.

### Medium — Chunk sort `O(n√n)`

Divides the numbers into chunks of roughly √n elements and pushes each chunk to stack b in order, then reassembles. Efficient for lists of ~100 elements.

### Complex — Radix sort `O(n log n)`

Sorts by processing numbers bit by bit, pushing to stack b based on each bit's value, then pulling back. Scales well for lists of 500+ elements.

### Adaptive

Uses the sortedness index to pick the most efficient algorithm automatically, considering both input size and how out-of-order the list already is.

---

## Sortedness index

A value between `0.0` and `1.0` that measures how disordered the input is before any operation runs.

- `0.0` — perfectly sorted list.
- `1.0` — maximally disordered list.

It is calculated by scanning the list in consecutive pairs. Each pair where the left element is greater than the right counts as a mistake. The index equals the number of mistakes divided by the total number of pairs examined.

```
index = mistakes / (n - 1)
```

The adaptive strategy uses this index together with the input size to decide which algorithm will produce the fewest operations.

---

## Benchmark mode

When the `--bench` flag is present, the program prints a summary to `stderr` after sorting. This output is separate from the operation list, therefore going to  `stdout`, so piping the result is not affected.

The benchmark summary includes:

- Sortedness index of the original input
- Name of the algorithm selected
- Total number of operations executed
- Breakdown of each individual operation type and its count

Example output written in stderr:

```
[bench] disorder: 47.39%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 797
[bench] sa: 0 sb: 0 ss: 0 pa: 100 pb: 100
[bench] ra: 404 rb: 96 rr: 0 rra: 0 rrb: 97 rrr: 0
```

---

## Flags

Flags must appear **before** the list of numbers.

| Flag | Effect |
|------|--------|
| `--simple` | Forces bubble sort regardless of input size. |
| `--medium` | Forces chunk sort regardless of input size. |
| `--complex` | Forces radix sort regardless of input size. |
| `--bench` | Enables benchmark mode. Prints stats to stderr after sorting. |

---

## Instructions

### Building the project

The project is built with the included `Makefile`. It first compiles the `ft_printf`
library for later use, and then the program itself, always with the `-Wall
-Wextra -Werror` flags. The project includes the common Makefile functions, both for the main project and the bonus section.

```bash
make
make bonus
make clean
make fclean
make re
```

### Running push_swap

```bash
./push_swap [flags] number1 number2 number3 ...
```

Examples:

```bash
./push_swap 4 2 7 1 5
./push_swap --bench 4 2 7 1 5
./push_swap --complex 4 2 7 1 5
./push_swap --bench --simple 3 1 2
```

To check the result is valid, pipe the output into the provided Linux checker, or into
our own checker built with `make bonus`:

```bash
./push_swap 4 2 7 1 5 | ./checker_linux 4 2 7 1 5
./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5
```

---

## Bonus Section: Checker
The `checker` program verifies that a sequence of operations actually sorts the stack.

**Our approach.** `checker` receives the same list of integers as `push_swap` as
command-line arguments and builds stack `a` from them, validating the input exactly
like `push_swap`: rejecting non-integers, values outside the `int` range and
duplicates. It then reads operations from **standard input** one line at a time with
`get_next_line`, applying each one to the stacks as it is read. Every operation is
matched against the eleven valid instructions; any unknown or malformed line is treated
as an error. Once the input ends, it checks the final state:

- prints `OK` if stack `a` is sorted and stack `b` is empty,
- prints `KO` otherwise,
- prints `Error` (to `stderr`) if the arguments are invalid or an instruction does not
  exist.

**Usage.** Feed the operations through standard input — typically by piping them
straight from `push_swap`:

```bash
./push_swap 4 2 7 1 5 | ./checker 4 2 7 1 5
echo -e "pb\npb\nsa" | ./checker 4 2 7 1 5
echo -e "sa\nfoo" | ./checker 4 2 7 1 5
```

---

## Resources

- **Algorithm visualizations** — YouTube videos showing how the different sorting
  strategies move data step by step, which helped to design and reason about the
  operation sequences.
- **C documentation** — the standard library and system call manuals consulted directly
  from the terminal for the authorized functions (`read`, `write`, `malloc`,
  `free`, `exit`).
- **AI** — used as a support tool for debugging and locating errors (tracking down edge
  cases, memory issues and unexpected behavior), not for generating the algorithms
  themselves.

