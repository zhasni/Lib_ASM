/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_isupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 15:00:47 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_isupper(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("isupper    %i = %i\n", i, isupper(i));
		printf("ft_isupper %i = %i\n\n", i, ft_isupper(i));
		i++;
	}
	return (0);
}
