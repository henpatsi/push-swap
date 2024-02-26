# push-swap

A program that attempts to find the minimum number of moves to sort a stack using a specific set of moves and one helper stack. The program outputs the shortest list of moves that it found. Includes a checker program that tests if the outputted list of instructions leads to a sorted stack.

### Running push_swap

The stack can be given as separate arguments or as a string.

The first number corresponding to the number at the top of the stack.

`./push_swap 5 3 1 2 4`

or 

`./push_swap "5 3 1 2 4"`

### Running the checker

The checker takes the same argument(s) as push_swap, then waits for sorting instructions from the standard input.

`./checker 5 3 1 2 4`

Especially for larger stacks, it is easiest to run by piping the output of push_swap to the checker.

`ARGS="5 3 1 2 4"; ./push_swap $(ARGS) | ./checker $(ARGS)`

### Allowed moves

- pa - pushed from stack b to stack a
- pb - pushed from stack a to stack b
- sa - swaps the top two elements of stack a
- sb - swaps the top two elements of stack b
- ss - performs sa and sb simultaneously
- ra - shifts all elements of stack a up one (first becomes last)
- rb - shifts all elements of stack b up one (first becomes last)
- rr - performs ra and rb simultaneously
- rra - shifts all elements of stack a down one (last becomes first)
- rrb - shifts all elements of stack a down one (last becomes first)
- rrr - performs rra and rrb simultaneously
