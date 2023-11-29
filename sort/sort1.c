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

/* Returns the position where a given node of stack_a should be in stack_b*/
t_list	*lst_get_insert_b(t_list **stack_b, t_list *a)
{
	t_list	*b;
	t_list	*b2;
	int		check;

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
		if (!b)
			b = *stack_b;
		return (b);
	}
	return (NULL);
}

/* Calculates mov for a given item of stack_a
	Mov is the minimum number of instructions required to move an item
	from stack_a to its correct position in stack_b
*/
void	calc_mov(t_list **stack_b, t_list *a)
{
	t_list	*b;

	b = lst_get_insert_b(stack_b, a);
	if (b)
	{
		a->mov = a->out + b->out + 1;
		a->mov_a = a->out * a->dir;
		a->mov_b = b->out * b->dir;
		if (ft_max(a->pos, b->pos) < a->mov)
		{
			a->mov = ft_max(a->pos, b->pos);
			a->mov_a = a->pos - 1;
			a->mov_b = b->pos - 1;
		}
		if (ft_max(a->pos_rev, b->pos_rev) < a->mov)
		{
			a->mov = ft_max(a->pos_rev, b->pos_rev) + 1;
			a->mov_a = -a->pos_rev;
			a->mov_b = -b->pos_rev;
		}
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
		calc_mov(stack_b, node);
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

	if (!b)
		return ;
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
