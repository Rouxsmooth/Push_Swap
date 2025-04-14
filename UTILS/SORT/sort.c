/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:03:51 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/14 15:55:10 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	reverse_sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	if (!(*stack)->next)
		return ;
	second = *(int *)(*stack)->next->content;
	if (!(*stack)->next->next)
	{
		if (first < second)
			ft_s(NULL, stack, 'b');
		return ;
	}
	//print_stack(*stack, "b");
	third = *(int *)(*stack)->next->next->content;
	if (is_sorted(*stack))
		return (ft_r(NULL, stack, 'b'), ft_s(NULL, stack, 'b'));
	else if (first < second && second > third && first < third)
		return (ft_r(NULL, stack, 'b'));
	else if (first > second && second < third && first > third)
		return (ft_rr(NULL, stack, 'b'), ft_s(NULL, stack, 'b'));
	else if (first > second && second < third && third < second)
		return (ft_rr(NULL, stack, 'b'));
	else if (first < second && second > third && first > third)
		return (ft_s(NULL, stack, 'b'));
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	if (!(*stack)->next->next)
	{
		if (first > second)
			ft_s(stack, NULL, 'a');
		return ;
	}
	third = *(int *)(*stack)->next->next->content;
	if (first > second && second < third && first < third)
		return (ft_s(stack, NULL, 'a'));
	else if (first > second && second > third)
		return (ft_s(stack, NULL, 'a'), ft_rr(stack, NULL, 'a'));
	else if (first > second && second < third && first > third)
		return (ft_r(stack, NULL, 'a'));
	else if (first < second && second > third && first < third)
		return (ft_s(stack, NULL, 'a'), ft_r(stack, NULL, 'a'));
	else if (first < second && second > third && first > third)
		return (ft_rr(stack, NULL, 'a'));
}

void	sort_six(t_stack **a, t_stack **b, int median)
{
	partition_a(a, b, median);
	sort_three(a);
	reverse_sort_three(b);
	while (*b)
		ft_p(a, b, 'a');
	return ;
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	bit_pos;
	int	count;

	bit_pos = 1;
	while (!is_sorted(*a))
	{
		count = 0;
		while (*a && count++ < size && !is_sorted(*a))
		{
			if (!((*a)->index & bit_pos))
				ft_p(a, b, 'b');
			else
				ft_r(a, NULL, 'a');
		}
		while (*b)
			ft_p(a, b, 'a');
		bit_pos *= 2;
	}
	return ;
}
