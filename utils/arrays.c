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
