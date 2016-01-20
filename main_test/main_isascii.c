/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:54:34 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 18:00:17 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isascii(int c);

int		main(void)
{
	int i = -10;

	while(i < 250)
	{
		printf("isascii    %i = %i\n", i, isascii(i));
		printf("ft_isascii %i = %i\n\n", i, ft_isascii(i));
		i++;
	}
	return (0);
}
