/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:05:40 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 01:06:13 by mzaian           ###   ########.fr       */
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
	return (temp);
}

void	partition_a(t_list **a, t_list **b, int median)
{
	int		len;
	int		i;

	len = ft_lstsize(*a);
	i = 0;
	while (i < len)
	{
		if (*(int *)(*a)->content < median)
			ft_p(a, b, 'a');
		else
			ft_r(a, b, 'a');
		i++;
	}
}
