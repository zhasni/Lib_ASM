/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:49:36 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/25 18:34:34 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char		*ft_strcat(char *dest, const char *src);

int		main(void)
{
	const char	src[20] = "zinedine";
	char		dest[40] = "je m'appelle ";
	char		dest1[20] = "je m'appelle ";
	char		*dest2 = 0;

	printf("strcat = %s\n", strcat(dest, src));
	printf("ft_strcat = %s\n", ft_strcat(dest1, src));
	printf("test NULL\n\n");
	// printf("NULL strcat = %s\n", strcat(dest2, src));
	printf("NULL ft_strcat = %s\n", ft_strcat(dest2, src));
	return (0);
}
/*
char		*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
*/