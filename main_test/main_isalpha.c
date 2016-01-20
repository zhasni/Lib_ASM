/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:16:11 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 18:02:50 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isalpha(int c);

int		main(void)
{
	int	i = -10;
	while (i < 150)
	{
		printf("isalpha    %i = %i\n", i, isalpha(i));
		printf("FT_isalpha %i = %i\n\n", i, ft_isalpha(i));
		i++;
	}
	return(0);
}
