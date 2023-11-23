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
#include "./utils/arrays.c"
#include "./utils/list.c"
#include "./instructions/instructions1.c"
#include "./instructions/instructions2.c"
#include "./instructions/instructions3.c"
#include "./sort/sort1.c"

#include <stdio.h>

// Prints the items of two stacks
void	lst_print(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = *stack_a;
	node_b = *stack_b;
	printf("\nIdx\tPos\tDir\tOut\tMov\t|\tIdx\tPos\tDir\tOut\tMov\n");
	// printf("\nNum\tPos\tIdx\tMov\t|\tNum\tPos\tIdx\tMov\n");
	while (node_a || node_b)
	{
		if (node_a)
		{
			printf("%i\t%i\t%i\t%i\t%i\t|\t", node_a->index, node_a->pos, node_a->dir, node_a->out, node_a->mov);
			// printf("%i\t%i\t%i\t%i\t|\t", node_a->num, node_a->pos, node_a->index, node_a->mov);
			node_a = node_a->next;
		}
		else
			printf("\t\t\t\t\t|\t");
			// printf("\t\t\t\t|\t");
		if (node_b)
		{
			printf("%i\t%i\t%i\t%i\t%i\t\n", node_b->index, node_b->pos, node_b->dir, node_b->out, node_b->mov);
			// printf("%i\t%i\t%i\t%i\n", node_b->num, node_b->pos, node_b->index, node_b->mov);
			node_b = node_b->next;
		}
		else
			printf("\t\t\t\t\n");
			// printf("\t\t\t\n");
	}
	printf("\n");
}

// Sorts the elements in stack_a
void	sort(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list *a;

	pb(stack_a, stack_b, counter);
	pb(stack_a, stack_b, counter);
	lst_update(stack_a, stack_b);
	/*REMOVE*/	lst_print(stack_a, stack_b);
	while ((*stack_a)->next)
	{
		a = lst_next_mov(stack_a);
		move_b(stack_a, stack_b, a, counter);
		lst_update(stack_a, stack_b);
		/*REMOVE*/	lst_print(stack_a, stack_b);

	}
	
}

// Sorts the stack, using push/swap
int	push_swap(int **stack_int)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		counter;
	int		check;

	counter = 0;
	stack_a = int_to_lst(stack_int);
	stack_b = (t_list **)calloc(1, sizeof(t_list));

	lst_update(stack_a, stack_b);
	/*REMOVE*/	lst_print(stack_a, stack_b);
	if (!lst_is_sorted(stack_a))
		sort(stack_a, stack_b, &counter);	
	/*REMOVE*/	check = lst_is_sorted(stack_a);
	free_list(stack_a);
	free_list(stack_b);
	return (check);
}

int	main_test(int argc, char **argv)
{
	int	**stack_int;
	// int	instructions;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_int = list_map(argc, argv);
	push_swap(stack_int);
	free_array((void **)stack_int);
	return (0);
}

int	main(void)
{
	/*
	char	*argv[5];

	argv[0] = "./a.out";
	argv[1] = "1123";
	argv[2] = "422";
	argv[3] = "71";
	argv[4] = "417";
	main_test(5, argv);
	*/
	
	char	*argv[2];

	argv[0] = "2";
	argv[1] = "23 24 25 30 1 2 7 8 9 15 16 6";

	main_test(2, argv);	
	
	
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int	n;

	printf("argc = %i\n", argc);
	n = 0;
	while (n < argc)
	{
		printf("argv[%i] = %s\n", n, argv[n]);
		n++;
	}	
	return (0);
}
*/