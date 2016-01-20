/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:30:12 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isgraph(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isgraph    %i = %i\n", i, isgraph(i));
		printf("ft_isgraph %i = %i\n\n", i, ft_isgraph(i));
		i++;
	}
	return (0);
}
