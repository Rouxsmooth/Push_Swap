/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:33:58 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 13:34:18 by mzaian           ###   ########.fr       */
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
	int		size;
	t_stack	**a;
	t_stack	**b;

	if (argc <= 2)
		return (0);
	array = parse(argc, argv);
	if (!array)
		return (1);
	a = (t_stack **) ft_calloc(1, sizeof(t_stack *));
	b = (t_stack **) ft_calloc(1, sizeof(t_stack *));
	set_stacks(argc, array, a, b);
	size = stacksize(*a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 6)
		sort_six(a, b, find_median(array, argc - 1));
	else
		radix_sort(a, b, size);
	return ((ft_del(array), stackclear(a, ft_del),
			stackclear(b, ft_del), ft_del(a), ft_del(b)), 0);
}
	//print_stack(*a, "a");
	//print_stack(*b, "b");
