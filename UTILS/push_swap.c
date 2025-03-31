/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:33:58 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/31 12:02:47 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	quit(t_stack **a, t_stack **b)
{
	stackclear(a, ft_del);
	ft_del(a);
	ft_del(b);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		return (0);
	array = parse(&argc, argv);
	if (!array)
		return (1);
	a = (t_stack **) ft_calloc(1, sizeof(t_stack *));
	b = (t_stack **) ft_calloc(1, sizeof(t_stack *));
	set_stacks(argc, array, a, b);
	if (is_sorted(*a))
		return ((ft_del(array), stackclear(a, ft_del),
	stackclear(b, ft_del), ft_del(a), ft_del(b)), 0);
	if (stacksize(*a) <= 3)
		sort_three(a);
	else
		radix_sort(a, b, stacksize(*a));
	return ((ft_del(array), stackclear(a, ft_del),
	stackclear(b, ft_del), ft_del(a), ft_del(b)), 0);
}
//print_stack(*b, "b");
//print_stack(*a, "a");
