/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:23:09 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/17 16:10:33 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_s(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->next = temp;
	return ;
}

void	ft_ss(t_list **a, t_list **b)
{
	return (ft_s(a), ft_s(b));
}

void	ft_p(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!*to)
		return ;
	temp = *from;
	temp->next = *to;
	(*from) = (*from)->next;
	return ;
}

void	ft_r(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = temp;
	return ;
}

void	ft_rr(t_list **a, t_list **b)
{
	return (ft_r(a), ft_r(b));
}
