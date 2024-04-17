# Push_Swap

<img width="1282" alt="Screenshot 2567-04-17 at 16 00 07" src="https://github.com/Tisarji/push-swap-42cursus/assets/48820052/27bfd963-5b67-4acd-b0e6-e3e1c5d104f3">

# 📝 About Project

- This project involves sorting data on a stack using a limited set of operations, aiming for the lowest possible number of actions.
- The Push_swap project is an efficient and straightforward algorithm project that requires data sorting.
    
    You have a set of integer values, two stacks, and a set of operations to manipulate both stacks.
    
- The goal is to write a C program named push_swap, which calculates and displays the sorting operations for the integers received as arguments on the standard output.
- The project's learning objectives include rigor, the use of C, and understanding basic algorithms, particularly their complexity.
- You are allowed to use the following functions: malloc, free, exit, write, read.

# ⚙️ **List of Operations**

The program only operates with two stacks: stack A and stack B.

Initially, all numbers are added to stack A while stack B is kept empty.

Here are the possible operations:

| Code | Operations | Action |
| --- | --- | --- |
| sa | swap a | swaps the 2 top elements of stack a |
| sb | swap b | swaps the 2 top elements of stack b |
| ss | swap a + swap b | both sa and sb |
| pa | push a | moves the top element of stack b at the top of stack a |
| pb | push b | moves the top element of stack a at the top of stack b |
| ra | rotate a | shifts all elements of stack a from bottom to top |
| rb | rotate b | shifts all elements of stack b from bottom to top |
| rr | rotate a + rotate b | both ra and rb |
| rra | reverse rotate a | shifts all elements of stack a from top to bottom |
| rrb | reverse rotate b | shifts all elements of stack b from top to bottom |
| rrr | reverse rotate a + reverse rotate b | both rra and rrb |

# 🧮 Algorithm

<p align="center"><img width="600" alt="Screenshot 2567-04-17 at 13 39 40" src="https://github.com/Tisarji/push-swap-42cursus/assets/48820052/8847e227-011c-486e-aa9e-0a51771e9352"></p>

I utilize the `Butterfly` algorithm for sorting. Here's a brief overview:

- Initially, a chunk number is generated.

```c
int	parser_args(int argc, char *argv[])
{
	int	count;

	count = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	count = get_num_count(argv);
	if (count == 0)
		ft_msgerror("Error\\n");
	return (count);
}
```

- Next, I iterate through stack A looking for a number with an index smaller than the counter (number count in stack B).
- If such a number is found, I execute `pb` and `rb`.
- If not, I verify if the number is smaller than the counter plus chunk, and only execute `pb`.
- These operations are repeated until stack A is empty.
- As a result, stack B has numbers arranged like a 90-degree rotated butterfly 🦋.

```c
void	make_butterfly(t_stack *stack_a, t_stack *stack_b, int nrange)
{
	int		count;
	t_lst	*lst;

	count = 0;
	lst = stack_a->head;
	while (stack_a->head != NULL)
	{
		if (lst->idx <= count)
		{
			push_stack(stack_a, stack_b, "pb");
			rotate_stack(stack_b, "rb");
			++count;
		}
		else if (lst->idx <= count + nrange)
		{
			push_stack(stack_a, stack_b, "pb");
			++count;
		}
		else
			rotate_stack(stack_a, "ra");
		lst = stack_a->head;
	}
}
```

- Afterward, I loop through stack B and push the maximum index to stack A (i.e., `pa`) until stack B is empty.
- Following these operations, stack A becomes sorted.

The nrange number varies based on the count of numbers.

```c
int	generate_range(int size)
{
	int	nrange;

	nrange = 1;
	if (size < 50)
		nrange = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		nrange = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		nrange = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		nrange = 27 + (size - 350) / 15;
	else if (size > 500)
		nrange = 37 + (size - 500) / 20;
	return (nrange);
}
```

Hence, experimenting with the chunk number is necessary to achieve the optimal operation count.

# ⌨️ Usage

## **Requirements**

The program is written in the C language and requires the **gcc compiler** and some standard **C libraries** to run.

## **Instructions**

### **1. Compiling the program**

To compile the program, enter the following command:

```
$ cd path/to/push_swap && make
```

To compile the checker, enter:

```
$ cd path/to/push_swap && make bonus
```

### **2. How to run the program**

Execute the program with a set of numbers separated by a space:

```
./push_swap <Number>
```

To run the checker on push_swap, use the pipe:

```
ARG="<Number>"; ./push_swap $ARG | ./checker $ARG
```

Use `clean` to delete all object files, `fclean` to remove the executable and all object files, and `re` to recompile the program:

```
make clean / make fclean / make re / make bonus / make clean_bonus / make fclean_bonus / make re_bonus
```

# 🎥 Video

https://github.com/Tisarji/push-swap-42cursus/assets/48820052/b5a73ec0-11c7-4bb6-bdf1-ad966fe01e1d

