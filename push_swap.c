#include "push_swap.h"
#include "./utils/args_check.c"

#include <stdio.h>

int	main_test(int argc, char **argv)
{
	int	**stack_int;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}

	stack_int = list_map(argv);
	list_free((void **)stack_int);
	return (0);
}

int	main(void)
{
	char	*argv[2];

	argv[0] = "2";
	argv[1] = "2123 422 71 417 76 75";
	// argv[2] = "13 2";

	main_test(2, argv);
	return (0);
}