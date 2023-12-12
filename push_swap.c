/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:11 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/15 16:56:11 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "./utils/misc.c"
// #include "./utils/args_check.c"
// #include "./utils/list.c"
// #include "./utils/list_print.c"
// #include "./utils/arrays.c"
// #include "./instructions/instructions1.c"
// #include "./instructions/instructions2.c"
// #include "./instructions/instructions3.c"
// #include "./sort/sort0.c"
// #include "./sort/sort1.c"
// #include "./sort/sort2.c"

#include <stdio.h>

// Sorts the elements in stack_a, using stack_b
void	push_swap_new(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*temp;

	lst_update(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 5)
	{
		lst_print(stack_a, stack_b);
		temp = lst_get_mov_min(stack_a);
		move_b(stack_a, stack_b, temp, counter);
		lst_update(stack_a, stack_b);
	}
	lst_print(stack_a, stack_b);
	sort_b(stack_a, stack_b, counter);
	push_swap_simple(stack_a, stack_b, counter);
	lst_print(stack_a, stack_b);
	while (*stack_b)
	{
		move_a(stack_a, stack_b, counter);
		lst_print(stack_a, stack_b);
	}
	lst_update(stack_a, stack_b);
	move_top_a(stack_a, stack_b, lst_get_min(*stack_a, -1), counter);
	lst_print(stack_a, stack_b);
}

// Sorts the elements in stack_a, using stack_b
void	push_swap_sort(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*temp;

	lst_update(stack_a, stack_b);
	while ((*stack_a)->next)
	{
		lst_print(stack_a, stack_b);
		temp = lst_get_mov_min(stack_a);
		move_b(stack_a, stack_b, temp, counter);
		lst_update(stack_a, stack_b);
	}
	lst_print(stack_a, stack_b);
	sort_b(stack_a, stack_b, counter);
	temp = *stack_a;
	while (*stack_b)
	{
		pa(stack_a, stack_b, counter);
		if (*stack_b)
			if (temp->index < (*stack_a)->index
				&& temp->index > (*stack_b)->index)
				rra(stack_a, stack_b, counter);
	}
	if (temp->index < (*stack_a)->index)
		rra(stack_a, stack_b, counter);
	lst_print(stack_a, stack_b);
}

// Sorts an array of integers, using push/swap
int	push_swap(int **stack_int)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		counter;

	counter = 0;
	stack_a = int_to_lst(stack_int);
	stack_b = (t_list **)calloc(1, sizeof(t_list));
	lst_update(stack_a, stack_b);
	lst_print(stack_a, stack_b);
	if (!lst_is_sorted(stack_a))
	{
		if (ft_lstsize(*stack_a) < 6)
			push_swap_simple(stack_a, stack_b, &counter);
		else
			push_swap_new(stack_a, stack_b, &counter);
	}
	print_results(0, stack_a, stack_b, counter);
	free_list(stack_a);
	free_list(stack_b);
	return (counter);
}

// int	main_test(int argc, char **argv)
int	main(int argc, char **argv)
{
	int	**stack_int;

	if (argc < 2)
	{
		return (0);
	}
	stack_int = list_map(argc, argv);
	push_swap(stack_int);
	free_array((void **)stack_int);
	return (0);
}

/*
int	main(void)
{	
	char	*argv[2];

	argv[0] = "push_swap";
	argv[1] = "23 24 25 30 1 2 7 8 9 15 16 6";

	main_test(2, argv);	
	
	
	return (0);
}
*/