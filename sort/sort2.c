/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:01:16 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/27 22:01:16 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Sorts stack_b in descending order 
void	sort_b(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*max;
	t_list	*temp;

	if (!stack_b)
		return ;
	max = *stack_b;
	temp = *stack_b;
	while (temp)
	{
		if (temp->index > max->index)
			max = temp;
		temp = temp->next;
	}
	move_top_b(stack_a, stack_b, max, counter);		
}

// Simple algorithm for stacks of size n < 3
void	push_swap_simple(t_list **stack_a, t_list **stack_b, int *counter)
{
	if ((*stack_a)->index > ((*stack_a)->next)->index)
		sa(stack_a, stack_b, counter);
}

// Sorts the elements in stack_a, using stack_b
void	push_swap_sort(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list *temp;

	pb(stack_a, stack_b, counter);
	pb(stack_a, stack_b, counter);
	lst_update(stack_a, stack_b);
	while ((*stack_a)->next)
	{
		/*REMOVE*/	lst_print(stack_a, stack_b);
		temp = lst_next_mov(stack_a);
		move_b(stack_a, stack_b, temp, counter);
		lst_update(stack_a, stack_b);
	}
	/*REMOVE*/	lst_print(stack_a, stack_b);
	sort_b(stack_a, stack_b, counter);
	/*REMOVE*/	lst_print(stack_a, stack_b);
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
	/*REMOVE*/	lst_print(stack_a, stack_b);
}
