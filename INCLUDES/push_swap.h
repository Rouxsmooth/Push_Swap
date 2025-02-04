/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:23:35 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 01:15:09 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../../libft/INCLUDES/libft.h"

void	ft_p(t_list **a, t_list **b, int which);
void	ft_s(t_list **a, t_list **b, int which);
void	ft_r(t_list **a, t_list **b, int which);
void	ft_rr(t_list **a, t_list **b, int which);
int		split_parsing(char **argv, int *array);
int		acavparsing(int argc, char **argv, int *array);
void	print_list(t_list *list, char *name);
int		find_median(int *array, int len);
void	reverse_sort_three(t_list **stack);
void	sort_three(t_list **stack);
void	partition_a(t_list **a, t_list **b, int median);
int		*parse(int argc, char **argv);
void	turk_sort(t_list **a, t_list **b, int median, int size);
int		is_sorted(t_list *stack);

#endif