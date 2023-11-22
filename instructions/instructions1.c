/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:07:22 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/22 16:07:22 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	temp = ft_lstlast(*stack);
	temp->next = *stack;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
}

void	reverse(t_list **stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
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
}
