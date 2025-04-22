/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:54 by mzaian            #+#    #+#             */
/*   Updated: 2025/04/22 14:31:14 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/push_swap.h"

int	overflows_long(char *str)
{
	int	i;
	int	nbrlen;

	i = 0;
	nbrlen = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if ((!nbrlen && str[i] != '0') || (nbrlen))
				nbrlen++;
			if (nbrlen > 10)
				return (1);
		}
		if (!ft_isdigit(str[i]) && nbrlen)
			return (1);
		i++;
	}
	return (0);
}

int	right_format_input(char *str)
{
	int	i;
	int	has_nbrs;

	if (!has_digits(str))
		return (0);
	i = 0;
	has_nbrs = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			return (0);
		if (ft_isdigit(str[i]))
			has_nbrs = 1;
		if (ft_isspace(str[i]) && has_nbrs)
			return (0);
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && has_nbrs)
			return (0);
		i++;
	}
	return (1);
}

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
			|| has_alpha(parsing[i]) || overflows(ft_atol(parsing[i]))
			|| !right_format_input(parsing[i]))
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

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_strlen(argv[i + 1]))
			return (error(), 0);
		if (has_elsethan(argv[i + 1], &ft_isdigit))
			if (!right_format_input(argv[i + 1]))
				return (error(), 0);
		if (overflows(ft_atol(argv[i + 1])))
			return (error(), 0);
		if (already_exists(array, ft_atoi(argv[i + 1]), i))
			return (error(), 0);
		if (overflows_long(argv[i + 1]))
			return (error(), 0);
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (1);
}

int	*parse(int *argc, char **argv)
{
	int	*array;

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
