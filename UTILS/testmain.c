/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:59:07 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 01:02:02 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	rotate_accordingly(t_list **stack)
{
	int		value;
	int		index;
	t_list	*temp;

	value = *(int *)(*stack)->content;
	index = 0;
	temp = *stack;
	while (*(int *)temp->content < value)
	{
		temp = temp->next;
		index++;
	}
	if (index > ft_lstsize(*stack) / 2)
	{
		while (index-- > 0 || value < *(int *)(*stack)->content)
			ft_rr(stack, NULL, 'a');
	}
	else
	{
		while (index-- > 0 || value > *(int *)(*stack)->content)
			ft_r(stack, NULL, 'a');
	}
	return ;
}

int	find_unsorted_index(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	while (*(int *)temp->content < *(int *)temp->next->content)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		*array;
	int		*val;
	t_list	**a;
	t_list	**b;
	int		i;

	array = parse(argc, argv);
	if (!array)
		return (1);
	i = 0;
	a = (t_list **)ft_calloc(1, sizeof(t_list *));
	b = (t_list **)ft_calloc(1, sizeof(t_list *));
	while (i < argc - 1)
	{
		val = (int *)ft_calloc(1, sizeof(int));
		if (!array)
			return ((ft_del(array), ft_lstclear(a, ft_del)), 1);
		*val = array[i++];
		ft_lstadd_back(a, ft_lstnew(val));
	}
	return (0);
}
