/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:22:14 by marcofer          #+#    #+#             */
/*   Updated: 2023/06/26 13:55:56 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
