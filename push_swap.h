/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcofer <marcofer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:17:38 by marcofer          #+#    #+#             */
/*   Updated: 2023/11/09 11:17:38 by marcofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/ft_atoi.c"
# include "./libft/ft_bzero.c"
# include "./libft/ft_calloc.c"
# include "./libft/ft_isalnum.c"
# include "./libft/ft_isalpha.c"
# include "./libft/ft_isascii.c"
# include "./libft/ft_isdigit.c"
# include "./libft/ft_isprint.c"
# include "./libft/ft_itoa.c"
# include "./libft/ft_lstadd_back_bonus.c"
# include "./libft/ft_lstadd_front_bonus.c"
# include "./libft/ft_lstclear_bonus.c"
# include "./libft/ft_lstdelone_bonus.c"
# include "./libft/ft_lstiter_bonus.c"
# include "./libft/ft_lstlast_bonus.c"
# include "./libft/ft_lstmap_bonus.c"
# include "./libft/ft_lstnew_bonus.c"
# include "./libft/ft_lstsize_bonus.c"
# include "./libft/ft_memchr.c"
# include "./libft/ft_memcmp.c"
# include "./libft/ft_memcpy.c"
# include "./libft/ft_memmove.c"
# include "./libft/ft_memset.c"
# include "./libft/ft_putchar_fd.c"
# include "./libft/ft_putendl_fd.c"
# include "./libft/ft_putnbr_fd.c"
# include "./libft/ft_putstr_fd.c"
# include "./libft/ft_split.c"
# include "./libft/ft_strchr.c"
# include "./libft/ft_strdup.c"
# include "./libft/ft_striteri.c"
# include "./libft/ft_strjoin.c"
# include "./libft/ft_strlcat.c"
# include "./libft/ft_strlcpy.c"
# include "./libft/ft_strlen.c"
# include "./libft/ft_strmapi.c"
# include "./libft/ft_strncmp.c"
# include "./libft/ft_strnstr.c"
# include "./libft/ft_strrchr.c"
# include "./libft/ft_strtrim.c"
# include "./libft/ft_substr.c"
# include "./libft/ft_tolower.c"
# include "./libft/ft_toupper.c"

void	free_array(void **ptr);
int		**str_to_int(char **list_str);
void	msg_error(void);
void	check_repeat(int **list_int);
void	check_digit(char **list_str);
int		**list_map(int argc, char **argv);
int		push_swap(int **stack_int);

#endif
