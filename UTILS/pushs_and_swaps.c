/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs_and_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:10:37 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/18 09:57:02 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!*to)
		return ;
	temp = *from;
	temp->next = *to;
	(*from) = (*from)->next;
	return ;
}

void	ft_p(t_list **a, t_list **b, int which)
{
	if (which == 'a')
		return (write(1, &"pa\n", 3), ft_push(a, b));
	return (write(1, &"pb\n", 3), ft_push(b, a));
}

void	ft_swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next = temp;
	return ;
}

void	ft_s(t_list **a, t_list **b, int which)
{
	if (which == 'a')
		return (write(1, &"sa\n", 3), ft_swap(a));
	if (which == 'b')
		return (write(1, &"sb\n", 3), ft_swap(b));
	return (write(1, &"ss\n", 3), ft_swap(a), ft_swap(b));
}
