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
// # include "./libft/ft_atoi.c"
// # include "./libft/ft_bzero.c"
// # include "./libft/ft_calloc.c"
// # include "./libft/ft_isalnum.c"
// # include "./libft/ft_isalpha.c"
// # include "./libft/ft_isascii.c"
// # include "./libft/ft_isdigit.c"
// # include "./libft/ft_isprint.c"
// # include "./libft/ft_itoa.c"
// # include "./libft/ft_lstadd_back_bonus.c"
// # include "./libft/ft_lstadd_front_bonus.c"
// # include "./libft/ft_lstclear_bonus.c"
// # include "./libft/ft_lstdelone_bonus.c"
// # include "./libft/ft_lstiter_bonus.c"
// # include "./libft/ft_lstlast_bonus.c"
// # include "./libft/ft_lstmap_bonus.c"
// # include "./libft/ft_lstnew_bonus.c"
// # include "./libft/ft_lstsize_bonus.c"
// # include "./libft/ft_memchr.c"
// # include "./libft/ft_memcmp.c"
// # include "./libft/ft_memcpy.c"
// # include "./libft/ft_memmove.c"
// # include "./libft/ft_memset.c"
// # include "./libft/ft_putchar_fd.c"
// # include "./libft/ft_putendl_fd.c"
// # include "./libft/ft_putnbr_fd.c"
// # include "./libft/ft_putstr_fd.c"
// # include "./libft/ft_split.c"
// # include "./libft/ft_strchr.c"
// # include "./libft/ft_strdup.c"
// # include "./libft/ft_striteri.c"
// # include "./libft/ft_strjoin.c"
// # include "./libft/ft_strlcat.c"
// # include "./libft/ft_strlcpy.c"
// # include "./libft/ft_strlen.c"
// # include "./libft/ft_strmapi.c"
// # include "./libft/ft_strncmp.c"
// # include "./libft/ft_strnstr.c"
// # include "./libft/ft_strrchr.c"
// # include "./libft/ft_strtrim.c"
// # include "./libft/ft_substr.c"
// # include "./libft/ft_tolower.c"
// # include "./libft/ft_toupper.c"

// Push Swap
void	push_swap_simple(t_list **stack_a, t_list **stack_b, int *counter);
void	push_swap_sort(t_list **stack_a, t_list **stack_b, int *counter);
void	push_swap_new(t_list **stack_a, t_list **stack_b, int *counter);
int		push_swap(int **stack_int);

// Utils - Misc
int		is_positive(int num);
int		ft_min(int num1, int num2);
int		ft_max(int num1, int num2);

// Utils - List
void	lst_pos(t_list **stack);
void	lst_index(t_list **stack);
t_list	*lst_get_mov_min(t_list **stack);
t_list	*lst_get_idx_max(t_list **stack);
int		lst_is_sorted(t_list **stack);
void	lst_print_idx(t_list **stack_a, t_list **stack_b);
void	lst_print(t_list **stack_a, t_list **stack_b);
void	print_results(int i, t_list **stack_a, t_list **stack_b, int counter);

// Utils - Arrays
void	free_array(void **ptr);
void	free_list(t_list **stack);
int		**str_to_int(char **list_str);
t_list	**int_to_lst(int **stack_int);

// Utils - Arguments Check
void	msg_error(void);
void	check_repeat(int **list_int);
void	check_digit(char **list_str);
void	check_int(char **list_str);
int		**list_map(int argc, char **argv);

// Instructions
int		swap(t_list **stack);
int		push(t_list **stack_from, t_list **stack_to);
int		rotate(t_list **stack);
int		reverse(t_list **stack);
void	sa(t_list **stack_a, t_list **stack_b, int *counter);
void	sb(t_list **stack_a, t_list **stack_b, int *counter);
void	ss(t_list **stack_a, t_list **stack_b, int *counter);
void	pa(t_list **stack_a, t_list **stack_b, int *counter);
void	pb(t_list **stack_a, t_list **stack_b, int *counter);
void	ra(t_list **stack_a, t_list **stack_b, int *counter);
void	rb(t_list **stack_a, t_list **stack_b, int *counter);
void	rr(t_list **stack_a, t_list **stack_b, int *counter);
void	rra(t_list **stack_a, t_list **stack_b, int *counter);
void	rrb(t_list **stack_a, t_list **stack_b, int *counter);
void	rrr(t_list **stack_a, t_list **stack_b, int *counter);

// Sort
t_list	*lst_get_min(t_list *stack, int idx);
void	sort_simple_3(t_list **stack_a, t_list **stack_b, int *counter);
void	sort_simple_4(t_list **stack_a, t_list **stack_b, int *counter);
void	sort_simple_5(t_list **stack_a, t_list **stack_b, int *counter);
t_list	*lst_get_insert_b(t_list **stack_b, t_list *a);
void	calc_mov(t_list **stack_b, t_list *a);
void	lst_update(t_list **stack_a, t_list **stack_b);
void	move_top_a(t_list **stack_a, t_list **stack_b, t_list *a, int *counter);
void	move_top_b(t_list **stack_a, t_list **stack_b, t_list *b, int *counter);
void	sort_b(t_list **stack_a, t_list **stack_b, int *counter);
void	rot_top(t_list **stack_a, t_list **stack_b, t_list *a, int *counter);
void	rev_top(t_list **stack_a, t_list **stack_b, t_list *a, int *counter);
void	move_b(t_list **stack_a, t_list **stack_b, t_list *a, int *counter);
void	move_a(t_list **stack_a, t_list **stack_b, int *counter);

#endif
