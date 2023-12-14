/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:56:31 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/29 10:56:31 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_positive(int num)
{
	if (num < 0)
		return (0);
	return (1);
}

int	ft_min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

int	ft_max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

/*
int	ft_strcmp(const char *s1, const char *s2)
{
	int	diff;

	// ft_printf("ft_strcmp:\n");
	// printf("s1 = %s\n", s1);
	// printf("s2 = %s\n", s2);
	while (*s1 && *s1 == *s2)
	{
		// printf("*s1 = %c\n", *s1);
		// printf("*s2 = %c\n", *s2);
		s1++;
		s2++;
		diff = *s1 - *s2;
	}
	// printf("*s1 = %c\n", *s1);
	// printf("*s2 = %c\n", *s2);
	// printf("*diff = %i\n", diff);
	return (diff);
}
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
