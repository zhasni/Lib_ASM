/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:10:58 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 22:19:43 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_tolower(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("tolower    %i = %i\n", i, tolower(i));
		printf("FT_tolower %i = %i\n\n", i, ft_tolower(i));
		i++;
	}
	return (0);
}
