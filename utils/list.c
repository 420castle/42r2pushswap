/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:22:19 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/21 14:22:19 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	lst_index(t_list **stack)
{
	int		n;
	t_list	*min;
	t_list	*temp;

	n = 1;
	while (n <= ft_lstsize(*stack))
	{
		min = NULL;
		temp = *stack;
		while (temp)
		{
			if (temp->index == -1 && !min)
				min = temp;
			if (temp->index == -1)
				if (temp->num < min->num)
					min = temp;
			temp = temp->next;
		}
		min->index = n;
		n++;
	}
}

t_list	**int_to_lst(int **stack_int)
{
	t_list	**stack;
	t_list	*temp;
	int		n;

	stack = (t_list **)malloc(sizeof(t_list));
	*stack = NULL;
	n = 0;
	while (stack_int[n])
	{
		temp = ft_lstnew(NULL);
		temp->num = *stack_int[n];
		temp->index = -1;
		ft_lstadd_back(stack, temp);
		n++;
	}	
	return (stack);
}
