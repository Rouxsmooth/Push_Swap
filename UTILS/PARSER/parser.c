/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:54 by mzaian            #+#    #+#             */
/*   Updated: 2025/03/26 15:26:59 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

int	split_parsing(char **argv, int *array)
{
	char	**parsing;
	int		i;

	parsing = ft_split(argv[1], ' ');
	if (!parsing)
		return (error(), 0);
	i = 0;
	while (parsing[i])
	{
		if (!has_alpha(parsing[i]) && !already_exists(array, array[i], i))
			array[i] = ft_atoi(parsing[i]);
		i++;
	}
	while (1)
		;
	if (!has_alpha(parsing[i]))
		return ((free_splited(parsing, i), error(), 0));
	if (already_exists(array, array[i], i))
		return ((free_splited(parsing, i), error(), 0));
	return (1);
}

int	acavparsing(int argc, char **argv, int *array)
{
	int		i;
	int		j;
	char	*error_msg;

	i = 0;
	error_msg = "Argument type";
	while (i < argc - 1)
	{
		if (has_elsethan(argv[i + 1], &ft_isdigit))
		{
			j = 0;
			while (argv[i + 1][j])
			{
				if (!ft_isdigit(argv[i + 1][j]) && argv[i + 1][j] != '-')
					return (error(), 0);
				j++;
			}
		}
		array[i] = ft_atoi(argv[i + 1]);
		if (already_exists(array, array[i], i))
			return (error(), 0);
		i++;
	}
	return (1);
}

int	*parse(int argc, char **argv)
{
	int	*array;

	if (argc < 2)
		return (error(), (int *) NULL);
	array = (int *) ft_calloc(argc, sizeof(int));
	if (!array)
		return (error(), (int *) NULL);
	if (ft_strchr(argv[1], ' '))
	{
		if (!split_parsing(argv, array))
			return ((ft_del(array), (int *) NULL));
	}
	else
	{
		if (!acavparsing(argc, argv, array))
			return ((ft_del(array), (int *) NULL));
	}
	return (array);
}
