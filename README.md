# Push Swap

Push Swap is an algorithm project that aims to sort a stack of numbers in ascending order using a series of predefined movements on two stacks. This program displays the optimal sequence of movements to sort the input stack.

Movements:

- sa: Swap the first two elements of stack a.
- sb: Swap the first two elements of stack b.
- ss: Perform sa and sb simultaneously.
- pa: Move the first element from stack b to stack a.
- pb: Move the first element from stack a to stack b.
- ra: Rotate up all elements of stack a.
- rb: Rotate up all elements of stack b.
- rr: Perform ra and rb simultaneously.
- rra: Rotate down all elements of stack a.
- rrb: Rotate down all elements of stack b.
- rrr: Perform rra and rrb simultaneously.

Usage

To use Push Swap, follow these steps:

Clone this repository to your local machine.

Run the make command in the terminal to compile the program:

```
cd folder_to_push_swape
make
```

Once compiled, you can execute the program as follows:

```
./push_swap [list_of_numbers]
```

For example:

```bash
./push_swap 5 3 1 4 2
```

Will display:

```bash
pb
p
rra
sa
rra
pa
ra
ra
pa
ra
```