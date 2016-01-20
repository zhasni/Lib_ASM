/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:10:34 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/25 18:30:16 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

	int ft_strlen(const char *string);

int				main(void)
{
	const char	*str;
	const char	*str1 = 0;
	int			i;
	int			j;

	str = "zinedinecoucoucaca";
	i = strlen(str);
	j = ft_strlen(str);
	printf("strlen    = %d\n", i);
	printf("ft_strlen = %d\n", j);
	printf("\ntest NULL\n\n");
	// printf("strlen    = %zn\n", strlen(str1));
	printf("ft_strlen = %d\n", ft_strlen(str1));
	return (0);
}
