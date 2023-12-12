/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:54:46 by marcofer          #+#    #+#             */
/*   Updated: 2023/12/11 16:54:46 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Get the node with the lowest index, higher than a given index
t_list	*lst_get_min(t_list *stack, int idx)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index > idx)
		{
			if (!min)
				min = stack;
			else if (stack->index < min->index)
				min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

// Simple algorithm for stacks of size n = 3
void	sort_simple_3(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*a1;
	t_list	*a2;

	a1 = lst_get_min(*stack_a, -1);
	a2 = lst_get_min(*stack_a, a1->index);
	if (*stack_a == a1 && (*stack_a)->next != a2)
	{
		sa(stack_a, stack_b, counter);
		ra(stack_a, stack_b, counter);
	}
	else if (*stack_a != a1 && *stack_a != a2)
	{
		if ((*stack_a)->next == a1)
			ra(stack_a, stack_b, counter);
		else
			sa(stack_a, stack_b, counter);
	}
	if (*stack_a == a2)
	{
		if ((*stack_a)->next == a1)
			sa(stack_a, stack_b, counter);
		else
			rra(stack_a, stack_b, counter);
	}
	lst_pos(stack_a);
}

// Simple algorithm for stacks of size n = 4
void	sort_simple_4(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*a1;

	if (lst_is_sorted(stack_a))
		return ;
	lst_pos(stack_a);
	a1 = lst_get_min(*stack_a, -1);
	move_top_a(stack_a, stack_b, a1, counter);
	pb(stack_a, stack_b, counter);
	sort_simple_3(stack_a, stack_b, counter);
	pa(stack_a, stack_b, counter);
	lst_pos(stack_a);
}

// Simple algorithm for stacks of size n = 5
void	sort_simple_5(t_list **stack_a, t_list **stack_b, int *counter)
{
	t_list	*a1;

	if (lst_is_sorted(stack_a))
		return ;
	lst_pos(stack_a);
	a1 = lst_get_min(*stack_a, -1);
	move_top_a(stack_a, stack_b, a1, counter);
	pb(stack_a, stack_b, counter);
	sort_simple_4(stack_a, stack_b, counter);
	pa(stack_a, stack_b, counter);
	lst_pos(stack_a);
}

// Simple algorithm for stacks of size n < 6
void	push_swap_simple(t_list **stack_a, t_list **stack_b, int *counter)
{
	if (lst_is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a, stack_b, counter);
	if (ft_lstsize(*stack_a) == 3)
		sort_simple_3(stack_a, stack_b, counter);
	if (ft_lstsize(*stack_a) == 4)
		sort_simple_4(stack_a, stack_b, counter);
	if (ft_lstsize(*stack_a) == 5)
		sort_simple_5(stack_a, stack_b, counter);
	lst_update(stack_a, stack_b);
}
