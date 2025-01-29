/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:54 by mzaian            #+#    #+#             */
/*   Updated: 2025/01/29 05:21:43 by mzaian           ###   ########.fr       */
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
		if (has_elsethan(argv[i + 1], &ft_isdigit))
			return (display_error(error_msg), 0);
		array[i] = ft_atoi(argv[i + 1]);
		ft_printf("has ? %d in '%s' : %d\n", has_elsethan(argv[i + 1], &ft_isdigit), argv[i + 1], array[i]);
		i++;	
	}
	return (1);
}
