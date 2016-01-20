/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isxdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:54:12 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isxdigit(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isxdigit    %i = %i\n", i, isxdigit(i));
		printf("ft_isxdigit %i = %i\n\n", i, ft_isxdigit(i));
		i++;
	}
	return (0);
}
