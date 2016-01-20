/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isblank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:24:17 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isblank(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isblank    %i = %i\n", i, isblank(i));
		printf("ft_isblank %i = %i\n\n", i, ft_isblank(i));
		i++;
	}
	return (0);
}
