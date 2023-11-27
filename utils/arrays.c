/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:48:51 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/16 14:48:51 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Frees all elements of an array, including the pointer
void	free_array(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

// Frees the memory of all the nodes in a list
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

// Converts an array of strings into an array of integers
int	**str_to_int(char **list_str)
{
	int		**list_int;
	size_t	n;

	n = 0;
	while (list_str[n])
		n++;
	list_int = malloc(sizeof(int *) * (n + 2));
	if (!list_int)
		return (NULL);
	n = 0;
	while (list_str[n])
	{
		list_int[n] = malloc(sizeof(int));
		if (!list_int[n])
		{
			free_array((void **)list_int);
			return (NULL);
		}
		*list_int[n] = ft_atoi(list_str[n]);
		n++;
	}
	list_int[n] = NULL;
	return (list_int);
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
