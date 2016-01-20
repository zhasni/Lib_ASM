/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:15:00 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/26 12:07:11 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int		main(void)
{
	char	src[20] = "zinedine";
	char	tmp[10] = "bonjour";
	char	str1[10] = "hello";
	char	str2[10] = "hello";

	char	*null = 0;
	int		i = 100;
	size_t	n = 2;

	printf("avant, src  = %s, %p\n", src, src);
	printf("memset      i=%i n=%zu = %p\n", i, n, memset((void *)src, i , n));
	printf("apres, src  = %s, %p\n", src, src);
	printf("avant, src1 = %s, %p\n", tmp, tmp);
	printf("FT_memset  i=%i n=%zu = %p\n", i, n, ft_memset((void *)tmp, i , n));
	printf("apres, src1 = %s, %p\n", tmp, tmp);

	// str1 = memset(str1, 'a', 1);
	printf("memset str1    = %s\n", (char *)memset(str1, 'a', 4));
	printf("%s\n", str1);
	// str2 = ft_memset(str2, 'a', 1);
	printf("FT_memset str1 = %s\n", (char *)ft_memset(str2, 'a', 4));
	printf("%s\n", str2);

printf("\nTEST NULL\n\n");

	printf("avant, null = %s, %p\n", null, null);
	printf("FT_memset  i=%i n=%zu = %p\n", i, n, ft_memset((void *)null, i , n));
	printf("apres, null = %s, %p\n", null, null);
	return (0);
}
/*
void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
*/