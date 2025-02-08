/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:05 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/08 18:10:48 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = stacklast(*stack);
	temp->next = *stack;
	curr = *stack;
	while (curr->next != temp)
		curr = curr->next;
	curr->next = NULL;
	*stack = temp;
	return ;
}

void	ft_rr(t_stack **a, t_stack **b, int which)
{
	if (which == 'a')
		return ((write(1, &"rra\n", 4)), ft_reverse_rotate(a));
	if (which == 'b')
		return (write(1, &"rrb\n", 4), ft_reverse_rotate(b));
	return ((write(1, &"rrr\n", 4),
			ft_reverse_rotate(a)), ft_reverse_rotate(b));
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	stackadd_back(stack, temp);
	*stack = temp->next;
	temp->next = NULL;
	return ;
}

void	ft_r(t_stack **a, t_stack **b, int which)
{
	if (which == 'a')
		return (write(1, &"ra\n", 3), ft_rotate(a));
	if (which == 'b')
		return (write(1, &"rb\n", 3), ft_rotate(b));
	return (write(1, &"rr\n", 3), ft_rotate(a), ft_rotate(b));
}
