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
