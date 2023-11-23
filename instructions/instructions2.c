/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:40:35 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/22 17:40:35 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Operation: swap b
void	sb(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_a = stack_a;
	swap(stack_b);
	ft_putendl_fd("sb", 1);
	*counter = *counter + 1;
}

// Operation: swap a + b
void	ss(t_list **stack_a, t_list **stack_b, int *counter)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	*counter = *counter + 1;
}

// Operation: push a
void	pa(t_list **stack_a, t_list **stack_b, int *counter)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	*counter = *counter + 1;
}

// Operation: push b
void	pb(t_list **stack_a, t_list **stack_b, int *counter)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
	*counter = *counter + 1;
}

// Operation: rotate a
void	ra(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_b = stack_b;
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
	*counter = *counter + 1;
}
