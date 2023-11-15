/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:41:35 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/15 16:41:35 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	msg_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit (0);
}

void	list_free(void **ptr)
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

void	check_repeat(int **list_int)
{
	int	i;
	int	j;

	i = 0;
	while (list_int[i])
	{
		j = i + 1;
		while (list_int[j])
		{
			if (*list_int[i] == *list_int[j])
			{
				list_free((void **)list_int);
				msg_error();
			}
			j++;
		}
		i++;
	}
}

void	check_digit(char **list_str)
{
	int	i;
	int	j;

	i = 0;
	while (list_str[i])
	{
		j = 0;
		if (list_str[i][j] == '-')
			j++;
		while (list_str[i][j])
		{
			if (!ft_isdigit(list_str[i][j]) && list_str[i][j] != ' ')
			{
				list_free((void *)list_str);
				free(list_str);
				msg_error();
			}			
			j++;
		}		
		i++;
	}
}

int	**list_str_to_int(char **list_str)
{
	int		**list_int;
	size_t	n;

	n = 0;
	while (list_str[n])
		n++;
	list_int = malloc(sizeof(int*) * (n+2));
	if (!list_int)
		return (NULL);		
	n = 0;
	while (list_str[n])
	{
		list_int[n] = malloc(sizeof(int));
		if (!list_int[n])
			list_free((void **)list_int);
		*list_int[n] = ft_atoi(list_str[n]);
		n++;
	}
	list_int[n] = NULL;
	return(list_int);
}

int	**list_map(char **argv)
{	
	char	**list_str;
	int		**list_int;

	if (!argv[1])
		msg_error();
	list_str = ft_split(argv[1], ' ');
	if (!list_str)
		msg_error();
	check_digit(list_str);
	list_int = list_str_to_int(list_str);
	list_free((void **)list_str);
	if (!list_int)	
		msg_error();
	check_repeat(list_int);
	return (list_int);
}
