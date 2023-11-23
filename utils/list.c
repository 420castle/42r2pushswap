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

// Assigns/Updates the position, direction and outside distance of every node
void	lst_pos(t_list **stack)
{
	int		n;
	t_list	*temp;

	if (!stack)
		return ;
	n = 1;
	temp = *stack;
	while (temp)
	{
		temp->pos = n;
		temp->mov = -1;
		if (ft_lstsize(*stack) == 1 || n <= ft_lstsize(*stack) / 2)
		{
			temp->dir = 1;
			temp->out = n - 1;
		}
		else
		{
			temp->dir = -1;
			temp->out = ft_lstsize(*stack) - n + 1;
		}
		temp = temp->next;
		n++;
	}
}

// Assigns an index to every node, by ascending order
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

// Get the node of the stack with the least potential movements
t_list	*lst_next_mov(t_list **stack)
{
	t_list	*next;
	t_list	*temp;

	if (!stack)
		return (NULL);	
	temp = *stack;
	next = *stack;
	while (temp)
	{
		if (temp->mov < next->mov)
			next = temp;
		temp = temp->next;
	}	
	return (next);
}

// Converts an array of integers to a list
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
	lst_index(stack);
	lst_pos(stack);
	return (stack);
}

// Checks if the list is sorted
int	lst_is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->num > (temp->next)->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
