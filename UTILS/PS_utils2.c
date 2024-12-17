/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:10:37 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/17 16:11:51 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_revr(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	(*stack)->next = last;
	last = *stack;
}
// fix rev rotate, here it loops and last is indeed before first, but not 
//first, it's kind of -1

void	ft_rrr(t_list **a, t_list **b)
{
	return (ft_revr(a), ft_revr(b));
}
