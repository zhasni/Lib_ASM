/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:53:35 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/24 22:18:46 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int		ft_toupper(int c);

int		main(void)
{
	int i = -10;

	while (i < 150)
	{
		printf("toupper    %i = %i\n", i, toupper(i));
		printf("ft_toupper %i = %i\n\n", i, ft_toupper(i));
		i++;
	}
	return (0);
}
