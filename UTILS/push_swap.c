/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:33:58 by mzaian            #+#    #+#             */
/*   Updated: 2024/12/18 17:00:00 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

void	display_error(char *output)
{
	return (start_colored_output(2, 31), ft_putstr_fd(output, 2),
		close_colored_output(2));
}

int	main(int argc, char **argv)
{
	int	*array;

	if (argc < 2)
		return (display_error("Error\n"), 1);
	array = ft_calloc(argc, sizeof(int));
	if (!array)
		return (display_error("Error on allocation\n"), 1);
	if (ft_strchr(argv[1],  ' '))
		if (!split_parsing(argv, array))
			return (free(array), 1);
	else 
		if (!acavparsing(argc, argv, array))
			return (free(array), 1);
	//currently array len is argc - 1
}
//I should propably change int *array to t_lists 