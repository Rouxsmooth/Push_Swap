/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:50:53 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/08 19:08:30 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

t_stack	*stacklast(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (stack);
}

void	print_stack(t_stack *stack, char *name)
{
	t_stack	*current;
	int		*value;

	current = stack;
	ft_printf("%s: ", name);
	while (current)
	{
		value = (int *)(current->content);
		ft_printf("%d -> ", *value);
		current = current->next;
	}
	ft_printf("NULL\n");
}

void	set_indexes(t_stack **first_node, int size)
{
	t_stack	*smallest_node;
	t_stack	*tmp;
	int		index;
	long	smallest;
	int		found;

	index = 0;
	while (index < size)
	{
		smallest = 2147483648;
		found = 0;
		tmp = *first_node;
		while (tmp)
		{
			if (*(int *)tmp->content < smallest && tmp->index == -1)
			{
				smallest_node = tmp;
				smallest = *(int *)tmp->content;
				found = 1;
			}
			tmp = tmp->next;
		}
		if (found)
			smallest_node->index = index++;
	}
}

void	set_stacks(int argc, int *array, t_stack **a, t_stack **b)
{
	int		i;
	int		*val;
	t_stack	*temp;

	i = 0;
	while (i < argc - 1)
	{
		val = (int *) ft_calloc(1, sizeof(int));
		if (!array)
			return (ft_del(array), quit(a, b));
		*val = array[i++];
		stackadd_back(a, stacknew(val));
	}
	temp = *a;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
	return (set_indexes(a, stacksize(*a)));
}
