/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:54 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/18 16:57:58 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

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

int	has_alpha(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			return (1);
		(*str)++;
	}
	return (0);
}

int	split_parsing(char **argv, int *array)
{
	char	**parsing;
	int		i;
	char	*error_msg;

	i = 0;
	error_msg = "Error on argument type\n";
	parsing = ft_split(argv[1], ' ');
	if (!parsing)
		return (display_error("Error on allocation\n"), 0);
	while (parsing[i])
		if (!has_alpha(parsing[i]))
			array[i] = ft_atoi(parsing[i]);
	if (!has_alpha(parsing[i]))
		return ((free_splited(parsing, i), display_error(error_msg)), 0);
	return (1);
}

int	acavparsing(int argc, char **argv, int *array)
{
	int		i;
	char	*error_msg;

	i = 0;
	error_msg = "Error on argument type\n";
	while (i < argc - 1)
	{
		if (ft_isdigit(argv[i + 1]))
			array[i] = ft_atoi(argv[i + 1]);
		i++;	
	}
	if (!ft_isdigit(argv[i + 1]))
		return (display_error(error_msg), 0);
	return (1);
}
