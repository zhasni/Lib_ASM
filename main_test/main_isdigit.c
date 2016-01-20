/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:13:03 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 18:14:26 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isdigit(int c);

int		main(void)
{
	int	i = -10;

	while (i < 150)
	{
		printf("isdigit    %i = %i\n", i, isdigit(i));
		printf("ft_isdigit %i = %i\n\n", i, ft_isdigit(i));
		i++;
	}
	return (0);
}
