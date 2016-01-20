/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:15:30 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/27 11:29:28 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_strlen(const char *string);

int		main(void)
{
	const char	str[10] = "zinedine";
	int			fd = 0;
	printf("str 	= %s\n", str);
	printf("ft_putstr_fd = \n");
	ft_putstr_fd(str, fd);
	return (0);
}
/*
void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
*/

/*
void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
*/
