/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:05 by marcofer          #+#    #+#             */
/*   Updated: 2023/12/12 15:33:05 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include "push_swap.h"

// Checks if an instruction is invalid
int	check_command(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
		|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
		|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
		|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
		|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
		|| ft_strcmp(str, "rrr") == 0)
		return (0);
	return (1);
}

// Executes a given instruction. Returns 0 if valid instruction
// Returns 1 if invalid instruction
// Returns 2 if instruction is null
int	instruction(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!str)
		return (2);
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		swap(stack_a);
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		swap(stack_b);
	if (ft_strcmp(str, "pa") == 0)
		push(stack_b, stack_a);
	if (ft_strcmp(str, "pb") == 0)
		push(stack_a, stack_b);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		rotate(stack_a);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		rotate(stack_b);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		reverse(stack_a);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		reverse(stack_b);
	if (check_command(str))
		ft_putendl_fd("Error", 1);
	return (check_command(str));
}

// Reads instructions on the terminal, executes them and
// Returns 1 if there's an error 
int	checker(t_list **stack_a, t_list **stack_b)
{
	char	**commands;
	char	*line;
	int		check;

	commands = malloc(sizeof(char *));
	*commands = NULL;
	check = 0;
	while (check == 0)
	{
		line = get_next_line(0, commands);
		check = instruction(stack_a, stack_b, line);
		free(line);
	}
	free(*commands);
	free(commands);
	return (check);
}

// int	main_test(int argc, char **argv)
int	main(int argc, char **argv)
{
	int		**stack_int;
	t_list	**stack_a;
	t_list	**stack_b;	

	if (argc < 2)
		return (0);
	stack_int = list_map(argc, argv);
	stack_a = int_to_lst(stack_int);
	stack_b = (t_list **)calloc(1, sizeof(t_list));
	if (checker(stack_a, stack_b) != 1)
	{
		if (lst_is_sorted(stack_a) && !(*stack_b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	free_array((void **)stack_int);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

/*
int	main(void)
{	
	char	*argv[2];

	argv[0] = "checker";
	argv[1] = "0 9 1 8 2";

	// ft_printf("Test");
	main_test(2, argv);	
		
	return (0);
}
*/