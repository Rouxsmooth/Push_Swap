/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:16:25 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 15:16:33 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	error(void)
{
	return (ft_putstr_fd("Error\n", 1), (void) 0);
}

void	free_splited(char **array, int error_index)
{
	int	i;

	i = 0;
	while (i < error_index)
	{
		ft_del(&array[i]);
		i++;
	}
	return (ft_del(array));
}

int	already_exists(int *array, int val, int size)
{
	int	i;

	if (!array || size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		if (array[i++] == val)
			return (1);
	}
	return (0);
}
