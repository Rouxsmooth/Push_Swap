/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.zaian <m.zaian@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:20:46 by m.zaian           #+#    #+#             */
/*   Updated: 2024/10/13 02:44:54 by m.zaian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (!needle[i])
		return ((char *) haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && haystack[i + j])
			j++;
		if (!needle[j])
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}

/*static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	#include <stdio.h>
	#include <string.h>
	printf("is siffler | %s ; %s\n",
		ft_strstr("Je ne sais siffler", "i"),
		ft_strcmp(ft_strstr("Je ne sais siffler", "i"),
		strstr("Je ne sais siffler", "i")) == 0 ? "SUCCESS" :  "FAIL");
	printf("iffler | %s ; %s\n",
		ft_strstr("Je ne sais siffler", "iffler"),
		ft_strcmp(ft_strstr("Je ne sais siffler", "iffler"),
		strstr("Je ne sais siffler", "iffler")) == 0 ? "SUCCESS" :  "FAIL");
}*/