/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:54 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/31 15:11:42 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

int	*split_parsing(char **argv, int *argc)
{
	int		*array;
	char	**parsing;
	int		i;

	parsing = ft_split(argv[1], ' ');
	if (!parsing)
		return (error(), (int *) NULL);
	*argc = 0;
	while (parsing[*argc])
		(*argc)++;
	(*argc)++;
	array = (int *) ft_calloc(*argc, sizeof(int));
	i = 0;
	while (parsing[i])
	{
		if (already_exists(array, ft_atol(parsing[i]), i)
			|| has_alpha(parsing[i]) || overflows(ft_atol(parsing[i])))
			return (free_splited(parsing),
				ft_del(array), error(), (int *) NULL);
		array[i] = ft_atoi(parsing[i]);
		i++;
	}
	free_splited(parsing);
	return (array);
}

int	acavparsing(int argc, char **argv, int *array)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc - 1)
	{
		if (has_elsethan(argv[i + 1], &ft_isdigit))
		{
			j = 0;
			while (argv[i + 1][j])
			{
				if (!ft_isdigit(argv[i + 1][j]) && argv[i + 1][j] != '-'
					&& ft_isdigit(argv[i + 1][j]))
					return (error(), 0);
				j++;
			}
		}
		if (overflows(ft_atol(argv[i + 1])))
			return (error(), 0);
		if (already_exists(array, ft_atoi(argv[i + 1]), i))
			return (error(), 0);
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (1);
}

int	*parse(int *argc, char **argv)
{
	int	*array;

	if (*argc < 2)
		return (error(), (int *) NULL);
	if (ft_strchr(argv[1], ' ') && *argc == 2)
		return (split_parsing(argv, argc));
	else
	{
		array = (int *)ft_calloc(*argc, sizeof(int));
		if (!acavparsing(*argc, argv, array))
			return ((ft_del(array), (int *) NULL));
	}
	return (array);
}
