/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:28:47 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 18:24:19 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isalnum(int c);

int		main(void)
{
	int	i = -10;

	while (i < 150)
	{
		printf("isalnum    %i = %i\n", i, isalnum(i));
		printf("FT_isalnum %i = %i\n\n", i, ft_isalnum(i));
		i++;
	}
	return (0);
}
