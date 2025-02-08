/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:50:53 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/08 18:21:07 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stacklast(*stack);
	if (!last)
		*stack = new;
	else
		last->next = new;
	return ;
}

void	stackclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*tempnext;

	while (*stack)
	{
		tempnext = (*stack)->next;
		del((*stack)->content);
		free(*stack);
		*stack = tempnext;
	}
	*stack = NULL;
	return ;
}

int	stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*stacknew(void *content)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
	return ;
}
