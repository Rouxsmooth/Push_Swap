/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:23:35 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 15:17:33 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/INCLUDES/libft.h"

typedef struct s_stack
{
	int				index;
	void			*content;
	struct s_stack	*next;
}	t_stack;

/* main */
void	quit(t_stack **a, t_stack **b);

/* stack_utils */
int		stacksize(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackclear(t_stack **stack, void (*del)(void *));
t_stack	*stacknew(void *content);
void	stackadd_front(t_stack **stack, t_stack *new);
void	set_indexes(t_stack **first_node, int size);
void	set_stacks(int argc, int *array, t_stack **a, t_stack **b);
t_stack	*stacklast(t_stack *stack);

/* parser */
int		split_parsing(char **argv, int *array);
int		acavparsing(int argc, char **argv, int *array);
int		*parse(int argc, char **argv);
void	error(void);
void	free_splited(char **array, int error_index);
int		already_exists(int *array, int val, int size);

/* sort_utils */
int		is_sorted(t_stack *stack);
int		is_reverse_sorted(t_stack *stack);
int		find_median(int *array, int len);
void	partition_a(t_stack **a, t_stack **b, int median);

/* rules */
void	ft_p(t_stack **a, t_stack **b, int which);
void	ft_s(t_stack **a, t_stack **b, int which);
void	ft_r(t_stack **a, t_stack **b, int which);
void	ft_rr(t_stack **a, t_stack **b, int which);

/* sort */
void	sort_three(t_stack **stack);
void	sort_six(t_stack **a, t_stack **b, int median);
void	radix_sort(t_stack **a, t_stack **b, int size);
void	reverse_sort_three(t_stack **stack);

/* testing */
void	print_stack(t_stack *stack, char *name);

#endif