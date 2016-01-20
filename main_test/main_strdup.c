/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:12:27 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/26 14:54:51 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);

int		main(void)
{
	const char str[] = "zinedine"
		;
	printf("strdup    = %s\n", strdup(str));
	// ft_strdup(str);
	printf("ft_strdup = %s\n", ft_strdup(str));
	return (0);
}
/*
char		*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
*/