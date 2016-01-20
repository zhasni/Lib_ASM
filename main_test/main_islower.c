/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_islower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:03:38 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_islower(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("islower    %i = %i\n", i, islower(i));
		printf("ft_islower %i = %i\n\n", i, ft_islower(i));
		i++;
	}
	return (0);
}
