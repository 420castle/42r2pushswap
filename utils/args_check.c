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
				free_array((void **)list_int);
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
				free_array((void *)list_str);
				msg_error();
			}
			j++;
		}
		i++;
	}
}

void	check_int(char **list_str)
{
	int		i;
	long	num;

	i = 0;
	while (list_str[i])
	{
		num = ft_atoi(list_str[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			free_array((void *)list_str);
			msg_error();
		}
		i++;
	}
}

int	**list_map(int argc, char **argv)
{
	char	**list_str;
	int		**list_int;
	int		n;
	
	if (argc == 2)
		list_str = ft_split(argv[1], ' ');
	else
	{
		list_str = malloc(argc * sizeof(char *));
		n = 0;
		while (n++ < argc - 1)
			list_str[n-1] = ft_strdup(argv[n]);
		list_str[n-1] = NULL;
	}	
	if (!list_str)
		msg_error();	
	check_digit(list_str);
	check_int(list_str);
	list_int = str_to_int(list_str);
	free_array((void **)list_str);
	if (!list_int)
		msg_error();
	check_repeat(list_int);
	return (list_int);
}
