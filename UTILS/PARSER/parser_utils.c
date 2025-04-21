/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:16:25 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/21 20:55:06 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

void	error(void)
{
	return (ft_putstr_fd("Error\n", 2), (void) 0);
}

void	free_splited(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_del(array[i]);
		i++;
	}
	return (ft_del(array));
}

int	already_exists(int *array, int val, int size)
{
	int	i;

	if (!array || size < 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (array[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	overflows(long nbr)
{
	if (nbr < 0)
		return (nbr < -2147483648);
	return (nbr > 2147483647);
}
