/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs_and_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:10:37 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/08 18:10:51 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = NULL;
	stackadd_front(to, temp);
	return ;
}

void	ft_p(t_stack **a, t_stack **b, int which)
{
	if (which == 'a')
		return (write(1, &"pa\n", 3), ft_push(b, a));
	return (write(1, &"pb\n", 3), ft_push(a, b));
}

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack))
		return ;
	if (!(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return ;
}

void	ft_s(t_stack **a, t_stack **b, int which)
{
	if (which == 'a')
		return (write(1, &"sa\n", 3), ft_swap(a));
	if (which == 'b')
		return (write(1, &"sb\n", 3), ft_swap(b));
	return (write(1, &"ss\n", 3), ft_swap(a), ft_swap(b));
}
