/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:47:36 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isspace(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isspace    %i = %i\n", i, isspace(i));
		printf("ft_isspace %i = %i\n\n", i, ft_isspace(i));
		i++;
	}
	return (0);
}
