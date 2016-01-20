/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ispunct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 16:02:31 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_ispunct(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("ispunct    %i = %i\n", i, ispunct(i));
		printf("ft_ispunct %i = %i\n\n", i, ft_ispunct(i));
		i++;
	}
	return (0);
}
