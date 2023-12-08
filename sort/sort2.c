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

/* Rotates stack_a and stack_b so that node *a goes to the top and is ready
	to be pushed to the top of stack b
*/
void	rot_top(t_list **stack_a, t_list **stack_b, t_list *a, int *counter)
{
	int	n;

	n = 0;
	while (n < ft_min(a->mov_a, a->mov_b))
	{
		rr(stack_a, stack_b, counter);
		n++;
	}
	while (n < a->mov_a)
	{
		ra(stack_a, stack_b, counter);
		n++;
	}
	while (n < a->mov_b)
	{
		rb(stack_a, stack_b, counter);
		n++;
	}
}

/* Reverse rotates stack_a and stack_b so that node *a goes to the top and
	is ready to be pushed to the top of stack b
*/
void	rev_top(t_list **stack_a, t_list **stack_b, t_list *a, int *counter)
{
	int	n;

	n = 0;
	while (n < ft_min(-a->mov_a, -a->mov_b))
	{
		rrr(stack_a, stack_b, counter);
		n++;
	}
	while (n < -a->mov_a)
	{
		rra(stack_a, stack_b, counter);
		n++;
	}
	while (n < -a->mov_b)
	{
		rrb(stack_a, stack_b, counter);
		n++;
	}
}

// Moves a node from stack_a to its correct position in stack_b 
void	move_b(t_list **stack_a, t_list **stack_b, t_list *a, int *counter)
{
	t_list	*b;

	b = lst_get_insert_b(stack_b, a);
	if (is_positive(a->mov_a) != is_positive(a->mov_b))
	{
		move_top_a(stack_a, stack_b, a, counter);
		move_top_b(stack_a, stack_b, b, counter);
	}
	if (is_positive(a->mov_a) && is_positive(a->mov_b))
		rot_top(stack_a, stack_b, a, counter);
	if (!is_positive(a->mov_a) && !is_positive(a->mov_b))
		rev_top(stack_a, stack_b, a, counter);
	pb(stack_a, stack_b, counter);
}
