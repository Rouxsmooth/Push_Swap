/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:27:45 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/18 11:52:37 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*first;
	t_list	*last;
	t_list	*sorted;
	int		size;
	int		nbg;
	int		*pivots;
}	t_stack;

int		f_high_low(t_stack *stack, int min, int max, int sort);
void	push_back(t_stack *a, t_stack *b);
void	smart_sorting(t_stack *a, t_stack *b);
int		smart_push(int value, t_stack *stack, int i, int sort);
int		to_push(t_stack *stack, int i, int sort);
int		init_stack(char **argv, t_stack *stack);
t_stack	*init_stack_empty(void);
void	sort_int_list(t_stack *stack);
t_list	*ft_lst_dup(t_list *lst);
int		f_pos(t_list *lst, int value);
int		f_elem(t_list *lst, int pos);
t_list	*f_prev(t_stack *a, int value);
int		is_sorted(t_stack *a, int order);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
#endif