/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:32:28 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isprint(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isprint    %i = %i\n", i, isprint(i));
		printf("ft_isprint %i = %i\n\n", i, ft_isprint(i));
		i++;
	}
	return (0);
}
