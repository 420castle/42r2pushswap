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
int	node_calc_mov(t_list **stack_a, t_list **stack_b, t_list *a)
{
	t_list	*b;
	int		mov;

	stack_a = stack_a;
	mov = a->out;
	if (ft_lstsize(*stack_b) > 2)
	{
		b = *stack_b;
		while (b->next && b->mov != -2)
			if (!(a->index < b->index && a->index > (b->next)->index))
				b = b->next;
			else
				b->mov = -2;
		if (b->next)
			mov = b->out;
	}
	a->mov = mov;
	return (mov);
}

// Updates stack_a and stack_b
void	lst_update(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;

	lst_pos(stack_a);
	lst_pos(stack_b);
	a = *stack_a;
	while (a)
	{
		node_calc_mov(stack_a, stack_b, a);
		a = a->next;
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

	if (!a)
		return ;
	move_top_a(stack_a, stack_b, a, counter);
	if (ft_lstsize(*stack_b) > 2)
	{
		b = *stack_b;
		while (b->next && b->mov != -2)
			if (!(a->index < b->index && a->index > (b->next)->index))
				b = b->next;
			else
				b->mov = -2;
		if (b->next)
			move_top_b(stack_a, stack_b, b->next, counter);
	}
	pb(stack_a, stack_b, counter);
}
