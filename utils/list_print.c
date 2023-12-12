/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:18:33 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/27 22:18:33 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "../push_swap.h"

// Prints the items of two stacks
void	lst_print_idx(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_a;
	t_list	*node_b;

	node_a = *stack_a;
	node_b = *stack_b;
	ft_printf("\nIdx\tPos\tDir\tOut\tMov\t|\tIdx\tPos\tDir\tOut\tMov\n");
	while (node_a || node_b)
	{
		if (node_a)
		{
			ft_printf("%i\t%i\t%i\t%i\t%i\t|\t", node_a->index, node_a->pos,
				node_a->dir, node_a->out, node_a->mov);
			node_a = node_a->next;
		}
		else
			ft_printf("\t\t\t\t\t|\t");
		if (node_b)
		{
			ft_printf("%i\t%i\t%i\t%i\t%i\t\n", node_b->index, node_b->pos,
				node_b->dir, node_b->out, node_b->mov);
			node_b = node_b->next;
		}
		else
			ft_printf("\t\t\t\t\n");
	}
}

// Prints the items of two stacks
void	lst_print(t_list **stack_a, t_list **stack_b)
{
	int	i;

	stack_a = stack_a;
	stack_b = stack_b;
	i = 0;
	if (i == 1)
	{
		lst_print_idx(stack_a, stack_b);
		ft_printf("\n");
	}
}

// Prints the end result
void	print_results(int i, t_list **stack_a, t_list **stack_b, int counter)
{
	if (i == 1)
	{
		ft_printf("\n");
		if (lst_is_sorted(stack_a) && !(*stack_b))
			ft_printf("OK");
		else
			ft_printf("Not sorted :(");
		ft_printf("\tSize = %i\t Steps = %i\n", ft_lstsize(*stack_a), counter);
	}
}
