/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaian <mzaian@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:33:58 by mzaian            #+#    #+#             */
/*   Updated: 2025/02/04 01:13:46 by mzaian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

int	*parse(int argc, char **argv)
{
	int	*array;

	if (argc < 2)
		return (display_error("Try ./push_swap <numbers>\n"), (int *) NULL);
	array = (int *) ft_calloc(argc, sizeof(int));
	if (!array)
		return (display_error("Memory allocation error\n"), (int *) NULL);
	if (ft_strchr(argv[1], ' '))
	{
		if (!split_parsing(argv, array))
			return ((ft_del(array), display_error("Parsing error")),
				(int *) NULL);
	}
	else
	{
		if (!acavparsing(argc, argv, array))
			return ((ft_del(array), display_error("Parsing error")),
				(int *) NULL);
	}
	return (array);
}

void	print_list(t_list *list, char *name)
{
	t_list	*current;
	int		*value;

	current = list;
	ft_printf("%s: ", name);
	while (current)
	{
		value = (int *)(current->content);
		ft_printf("%d -> ", *value);
		current = current->next;
	}
	ft_printf("NULL\n");
}

void	set_stack(int argc, int *array, t_list **a, t_list **b)
{
	int	i;
	int	*val;

	i = 0;
	while (i < argc - 1)
	{
		val = (int *) ft_calloc(1, sizeof(int));
		if (!array)
		{
			ft_del(array);
			ft_lstclear(a, ft_del);
			ft_del(a);
			ft_del(b);
			exit(0);
		}
		*val = array[i++];
		ft_lstadd_back(a, ft_lstnew(val));
	}
	return ;
}

int	main(int argc, char **argv)
{
	int		*array;
	t_list	**a;
	t_list	**b;

	if (argc <= 2)
		return (0);
	array = parse(argc, argv);
	if (!array)
		return (1);
	a = (t_list **) ft_calloc(1, sizeof(t_list *));
	b = (t_list **) ft_calloc(1, sizeof(t_list *));
	set_stack(argc, array, a, b);
	if (argc - 1 > 3)
		turk_sort(a, b, find_median(array, argc - 1), ft_lstsize(*a));
	else
		turk_sort(a, b, 0, ft_lstsize(*a));
	print_list(*a, "a");
	print_list(*b, "b");
	return ((ft_del(array), ft_lstclear(a, ft_del), ft_del(a), ft_del(b)), 0);
}

// while (i < argc - 1)
// {
// 	ft_lstadd_back(a, ft_lstnew(&array[i]));
// 	ft_printf("stack_a[%d] = %d\n", i, *(int *)(*a)->content);
// 	i++;
// }
// temp = *a;
// i = 0;
// while (i < argc - 1)
// {
// 	ft_printf("stack_a[%d] %d\n", i++, *(int *)temp->content);
// 	if (temp->next)
// 		temp = temp->next;
// }