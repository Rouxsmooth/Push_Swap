/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:05 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 00:58:53 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*curr;
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = ft_lstlast(*stack);
	temp->next = *stack;
	curr = *stack;
	while (curr->next != temp)
		curr = curr->next;
	curr->next = NULL;
	*stack = temp;
	return ;
}

void	ft_rr(t_list **a, t_list **b, int which)
{
	if (which == 'a')
		return ((write(1, &"rra\n", 4)), ft_reverse_rotate(a));
	if (which == 'b')
		return (write(1, &"rrb\n", 4), ft_reverse_rotate(b));
	return ((write(1, &"rrr\n", 4),
			ft_reverse_rotate(a)), ft_reverse_rotate(b));
}

void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	ft_lstadd_back(stack, temp);
	*stack = temp->next;
	temp->next = NULL;
	return ;
}

void	ft_r(t_list **a, t_list **b, int which)
{
	if (which == 'a')
		return (write(1, &"ra\n", 3), ft_rotate(a));
	if (which == 'b')
		return (write(1, &"rb\n", 3), ft_rotate(b));
	return (write(1, &"rr\n", 3), ft_rotate(a), ft_rotate(b));
}
