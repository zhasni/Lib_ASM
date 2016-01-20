/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:22:44 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/26 12:44:48 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char		dest[40] = {0};
	char		dst[40] = {0};
	const char	src[10] = "zinedine";
	size_t		n = 4;

	printf("dest = %s\n", dest);
	printf("memcpy = %p\n", memcpy((void *)dest, (const void *)src, n));
	printf("dest = %s\n\n", dest);
	printf("dst = %s\n", dst);
	printf("memcpy = %p\n", memcpy((void *)dst, (const void *)src, n));
	printf("dst = %s\n", dst);
	return (0);
}
/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	const char	*source;

	i = 0;
	tmp = (char *)dest;
	source = (const char *)src;
	while (i < n)
	{
		tmp[i] = source[i];
		i++;
	}
	return ((void *)tmp);
}
*/