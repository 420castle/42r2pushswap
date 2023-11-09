/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:11:57 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/09 11:11:57 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// free(ptr);
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
				list_free((void *)list_int);
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
	list_int = malloc(sizeof(int*) * n);
	if (!list_int)
		return (NULL);		
	n = 0;
	while (list_str[n])
	{
		list_int[n] = malloc(sizeof(int));
		*list_int[n] = ft_atoi(list_str[n]);
		n++;
	}
	list_int[n] = NULL;
	return(list_int);
}

int	**arg_check(char **argv)
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
	free(list_str);
	if (!list_int)	
		msg_error();
	check_repeat(list_int);
	return (list_int);
}

int	main_test(int argc, char **argv)
{
	int	**stack_int;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_int = arg_check(argv);
	return(*stack_int[0]);
	// return (0);
}

int	main(void)
{
	char	*argv[1];

	argv[0] = "2";
	argv[1] = "2123 422 71 417 76 75 71";
	// argv[2] = "13 2";

	main_test(2, argv);
	return (0);
}