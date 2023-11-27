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
#include "./utils/args_check.c"
#include "./utils/list.c"
#include "./utils/list_print.c"
#include "./utils/arrays.c"
#include "./instructions/instructions1.c"
#include "./instructions/instructions2.c"
#include "./instructions/instructions3.c"
#include "./sort/sort1.c"
#include "./sort/sort2.c"
// #include "./sort/sort.c"

#include <stdio.h>

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
	/*REMOVE*/	lst_print(stack_a, stack_b);
	if (!lst_is_sorted(stack_a))
	{
		if (ft_lstsize(*stack_a) < 3)
			push_swap_simple(stack_a, stack_b, &counter);
		else
			push_swap_sort(stack_a, stack_b, &counter);
	}
	free_list(stack_a);
	free_list(stack_b);
	return (counter);
}

// int	main(int argc, char **argv)
int	main_test(int argc, char **argv)
{
	int	**stack_int;

	if (argc < 2)
	{
		// ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_int = list_map(argc, argv);
	push_swap(stack_int);
	free_array((void **)stack_int);
	return (0);
}


int	main(void)
{	
	char	*argv[2];

	argv[0] = "2";
	// argv[1] = "23 24 25 30 1 2 7 8 9 15 16 6";
	// argv[1] = "30 1 2";
	argv[1] = "184215527 -723350085 463740688 481839014 288763059 -278965354 -856382516 132818436 -875701148 984014284 659484719 173310553 -82124580 606214737 585400780 -707962174 -148952384 -589078778 -344633569 288202122";

	main_test(2, argv);	
	
	
	return (0);
}
