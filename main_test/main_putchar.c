/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:22:32 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/26 21:20:21 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

int		main(void)
{
	int		i = -10;

	while (i < 150)
	{
		putchar(i);
		ft_putchar(i);
		printf("\n");
		i++;
	}
	return (0);
}
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
*/