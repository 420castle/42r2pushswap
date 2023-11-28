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
