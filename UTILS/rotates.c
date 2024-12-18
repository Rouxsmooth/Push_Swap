/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:05 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/18 09:56:30 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	ft_revever_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	(*stack)->next = last;
	last = *stack;
}
// fix rev rotate, here it loops and last is indeed before first, but not 
// first, it's kind of -1 ?

void	ft_rr(t_list **a, t_list **b, int which)
{
	if (which == 'a')
		return (write(1, &"rra\n", 4), ft_reverse_rotate(a));
	if (which == 'b')
		return (write(1, &"rrb\n", 4), ft_reverse_rotate(b));
	return (write(1, &"rrr\n", 4), ft_reverse_rotate(a), ft_reverse_rotate(b));
}

void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = temp;
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
