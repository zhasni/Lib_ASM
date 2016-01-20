/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:55:27 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 11:42:14 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);

int		main(void)
{
	int		i = -10;

	int		fd = 1;

	while (i < 150)
	{
		putchar(i);
		ft_putchar(i);
		ft_putchar_fd(i, fd);
		printf(" = %d\n", i);
		i++;
	}
	// char	c = 'z';
	// int		i = 1;
	// ft_putchar_fd(c, i);
	return (0);
}
/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/