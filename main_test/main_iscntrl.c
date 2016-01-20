/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_iscntrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:27:42 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_iscntrl(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("iscntrl    %i = %i\n", i, iscntrl(i));
		printf("ft_iscntrl %i = %i\n\n", i, ft_iscntrl(i));
		i++;
	}
	return (0);
}
