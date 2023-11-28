/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:44:21 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/23 16:44:21 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Calculates mov for a given item of stack_a
	Mov is the minimum number of instructions required to move an item
	from stack_a to its correct position in stack_b
*/
void	calc_mov(t_list **stack_a, t_list **stack_b, t_list *a)
{
	t_list	*b;
	t_list	*b2;
	int		check;

	stack_a = stack_a;
	a->mov = a->out + 1;
	if (ft_lstsize(*stack_b) > 1)
	{
		b = *stack_b;
		check = 0;
		while (b && check == 0)
		{
			b2 = b->next;
			if (!(b->next))
				b2 = *stack_b;
			if (a->index < b->index && a->index > b2->index)
				check = 1;
			b = b->next;
		}
		if (check == 0)
			b = lst_get_idx_max(stack_b);
		if (b)
			a->mov = a->mov + b->out;
	}
}

// Updates stack_a and stack_b
void	lst_update(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	lst_pos(stack_a);
	lst_pos(stack_b);
	node = *stack_a;
	while (node)
	{
		calc_mov(stack_a, stack_b, node);
		node = node->next;
	}
}

// Moves a node to the top of the stack a
void	move_top_a(t_list **stack_a, t_list **stack_b, t_list *a, int *counter)
{
	int	n;

	n = 0;
	while (n < a->out)
	{
		if (a->dir == 1)
			ra(stack_a, stack_b, counter);
		if (a->dir == -1)
			rra(stack_a, stack_b, counter);
		n++;
	}
}

// Moves a node to the top of the stack b
void	move_top_b(t_list **stack_a, t_list **stack_b, t_list *b, int *counter)
{
	int	n;

	n = 0;
	while (n < b->out)
	{
		if (b->dir == 1)
			rb(stack_a, stack_b, counter);
		if (b->dir == -1)
			rrb(stack_a, stack_b, counter);
		n++;
	}
}

// Moves a node from stack_a to its correct position in stack_b 
void	move_b(t_list **stack_a, t_list **stack_b, t_list *a, int *counter)
{
	t_list	*b;
	t_list	*b2;
	int		check;

	move_top_a(stack_a, stack_b, a, counter);
	if (ft_lstsize(*stack_b) > 1)
	{
		b = *stack_b;
		check = 0;
		while (b && check == 0)
		{
			b2 = b->next;
			if (!(b->next))
				b2 = *stack_b;
			if (a->index < b->index && a->index > b2->index)
				check = 1;
			b = b->next;
		}
		if (check == 0)
			b = lst_get_idx_max(stack_b);
		if (b)
			move_top_b(stack_a, stack_b, b, counter);
	}
	pb(stack_a, stack_b, counter);
}
