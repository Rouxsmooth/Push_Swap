/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 03:06:55 by m.zaian           #+#    #+#             */
/*   Updated: 2025/04/15 01:43:56 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/libft.h"

int	ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

int	has_alpha(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		if (ft_isalpha(str[i++]))
			return (1);
	return (0);
}
