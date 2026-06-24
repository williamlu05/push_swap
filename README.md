# Push-Swap
This proyect is all about arranging a list of numbers with only two stacks and a specific set of operations available.
To do so we had to use three different types of algorithms from a simple one to the more complex, and recieving in the end the list from smaller to bigger and more datta like the number of operations and the type of algorithm. 
## The rules
First of all we have two stacks a and b.

Stack a must have the list of numbers  and stack b must be empty at the beggining.

In order to arrange the number we could only use the following operations:

### Operations:
| Operation | Use |
| ----------|:---:|
| Swap a (sa) | Change the order of the two first elements in the stack a. If a is empty it does nothing |
| Swap b (sb) | Change the order of the two first elements in the stack b. If b is empty it does nothing |
| Swap a and b (ss) | Use sa and sb at the same time|
| Push a (pa) | Take the first element on stack b and place it in the first place on stack a. If b is empty it does nothing |
| Push b (pb) | Take the first element on stack a and place it in the first place on stack b. If a is empty it does nothing |
| Rotate a (ra) | Change the possition of every element on stack a, making the first element the last|
| Rotate b (rb) | Change the possition of every element on stack b, making the first element the last|
| Rotate a and b (rr) | Use ra and rb at the same time|
| Reverse rotate a (rra) | Change the possition of every element on stack a, making the last element the first|
| Reverse rotate b (rrb) | Change the possition of every element on stack b, making the last element the first|
| Reverse rotate a and b (rrr) | Use rra and rrb at the same time|

## Strategy
In order to sort the list of numbers, we had to apply different algorithms. 
### Simple--Bubble sort *O(n2)*
aaaa
### Medium--Chunk sort *O(n√n)*
aaaa
### Complex--Radix sort *O(n log n)*
aaaa
### Adaptative
aaaa

## Index
This is a number between 0 and 1 that reflects how well sorted the numbers are before running any operation.

0 resembles to a perfectly sorted list, and 1 to a full messed one.

To calculate this index you revise the list in pairs. For each pair that is not sorted you count a mistake. In the end the index will be the number of mistakes divided by the number of pairs looked.

## Benchmark
This mode alows the user to see some ussefull information about the programm.

(Image)

* index
* name of the strategy used
* total number of operations
* total number of each operation

This information must appear on the stderr and only when the flag is present.
## Flags
The flags must be placed before the numbers in order for the programm to work properly.

To force a specific algorithm you can use `--simple`, `--medium` or `--complex`.

To use the benchmark mode you can use the flag `--bench`
