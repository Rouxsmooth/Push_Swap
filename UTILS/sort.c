/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 04:03:51 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/29 10:00:21 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	find_median(int *array, int len)
{
	int	j;
	int	k;
	int	temp;

	j = 0;
	while (j < len - 1)
	{
		k = j + 1;
		while (k < len)
		{
			if (array[j] > array[k])
			{
				temp = array[j];
				array[j] = array[k];
				array[k] = temp;
			}
			k++;
		}
		j++;
	}
	temp = array[len / 2];
	return (ft_del(array), temp);
}

void	partition_a(t_list **a, t_list **b, int median)
{
	int	len;
	int	i;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len)
	{
		ft_printf("%d < %d ? %d\n", *(int *)(*a)->content, median, *(int *)(*a)->content < median);
		if (*(int *)(*a)->content < median)
			ft_p(a, b, 'b');
		else
			ft_r(a, b, 'a');
		i++;
	}
	return ;
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
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

void	turk_sort(t_list **a, t_list **b, int median)
{
	if (ft_lstsize(*a) <= 3)
		return (sort_three(a));
	partition_a(a, b, median);
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
	}
	return ;
}
