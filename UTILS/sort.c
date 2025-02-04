/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:03:51 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 01:06:25 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	reverse_sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	if (!(*stack)->next->next)
	{
		if (first < second)
			ft_s(stack, NULL, 'a');
		return ;
	}
	third = *(int *)(*stack)->next->next->content;
	if (is_sorted(*stack))
		return (ft_r(stack, NULL, 'a'), ft_s(stack, NULL, 'a'));
	else if (first < second && second > third && first < third)
		return (ft_r(stack, NULL, 'a'));
	else if (first > second && second < third && first > third)
		return (ft_rr(stack, NULL, 'a'), ft_s(stack, NULL, 'a'));
	else if (first > second && second < third && third < second)
		return (ft_rr(stack, NULL, 'a'));
	else if (first < second && second > third && first > third)
		return (ft_s(stack, NULL, 'a'));
}

void	sort_three(t_list **stack)
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

void	sort_six(t_list **a, t_list **b)
{
	sort_three(a);
	reverse_sort_three(b);
	while (*b)
		ft_p(a, b, 'b');
}

void	turk_sort(t_list **a, t_list **b, int median, int size)
{
	if (size <= 3)
		return (sort_three(a));
	partition_a(a, b, median);
	if (size <= 6)
		return (sort_six(a, b));
	while (*b)
	{
		ft_p(b, a, 'a');
		ft_r(a, b, 'a');
	}
	while (!is_sorted(*a))
	{
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ft_s(a, NULL, 'a');
		else
			ft_r(a, b, 'a');
		print_list(*a, "a");
	}
	return ;
}
