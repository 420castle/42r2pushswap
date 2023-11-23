/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:53:44 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/22 17:53:44 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Operation: push a
void	rb(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_a = stack_a;
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
	*counter = *counter + 1;
}

// Operation: rotate a + b
void	rr(t_list **stack_a, t_list **stack_b, int *counter)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	*counter = *counter + 1;
}

// Operation: reverse rotate a
void	rra(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_b = stack_b;
	reverse(stack_a);
	ft_putendl_fd("rra", 1);
	*counter = *counter + 1;
}

// Operation: reverse rotate b
void	rrb(t_list **stack_a, t_list **stack_b, int *counter)
{
	stack_a = stack_a;
	reverse(stack_b);
	ft_putendl_fd("rrb", 1);
	*counter = *counter + 1;
}

// Operation: reverse rotate a + b
void	rrr(t_list **stack_a, t_list **stack_b, int *counter)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_putendl_fd("rrr", 1);
	*counter = *counter + 1;
}
