/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:11 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/15 16:56:11 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./utils/args_check.c"
#include "./utils/arrays.c"
#include "./utils/list.c"
#include "./instructions/instructions1.c"

#include <stdio.h>

int	push_swap(int **stack_int)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = int_to_lst(stack_int);	
	stack_b = (t_list **)calloc(1, sizeof(t_list));
	lst_index(stack_a);
	// swap(stack_a);
	// swap(stack_b);
	rotate(stack_a);
	reverse(stack_a);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

int	main_test(int argc, char **argv)
{
	int	**stack_int;
	int	instructions;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	stack_int = list_map(argc, argv);
	instructions = push_swap(stack_int);
	free_array((void **)stack_int);
	return (0);
}

int	main(void)
{
	
	char	*argv[5];

	argv[0] = "./a.out";
	argv[1] = "1123";
	argv[2] = "422";
	argv[3] = "71";
	argv[4] = "417";
	main_test(5, argv);
	
	/*
	char	*argv[2];

	argv[0] = "2";
	argv[1] = "1123 422 71 417 76 75";

	main_test(2, argv);	
	
	*/
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int	n;

	printf("argc = %i\n", argc);
	n = 0;
	while (n < argc)
	{
		printf("argv[%i] = %s\n", n, argv[n]);
		n++;
	}	
	return (0);
}
*/