/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:14 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/22 17:40:14 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swaps the first two elements of a stack
int	swap(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return (0);
	if (!(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}

// Moves the first element of a stack to the top of another
int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*temp;

	if (!(*stack_from))
		return (0);
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
	return (1);
}

// Shifts up all elements of a stack
int	rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return (0);
	if (!(*stack)->next)
		return (0);
	temp = ft_lstlast(*stack);
	temp->next = *stack;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	return (1);
}

// Shifts down all elements of a stack
int	reverse(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!(*stack))
		return (0);
	if (!(*stack)->next)
		return (0);
	temp1 = *stack;
	temp2 = (*stack)->next;
	while (temp2->next)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
	return (1);
}

// Operation: swap a
void	sa(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_b = stack_b;
	swap(stack_a);
	ft_putendl_fd("sa", 1);
	*counter = *counter + 1;
}
