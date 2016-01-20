/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:39:36 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/25 16:46:23 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n);

int		main(void)
{
	char	str[20] = "zinedine";
	char	tmp[10] = "Hello";
	size_t	i = 1;

	printf("avant bzero str = <%s>\n", str);
	bzero(str, i);
	printf("apres bzero str = <%s>\n\n", str);
	printf("avant ft_bzero tmp = <%s>\n", tmp);
	ft_bzero(tmp, i);
	printf("apres ft_bzero tmp = <%s>\n", tmp);
	return (0);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*tmp;
// 	size_t	i;

// 	i = 0;
// 	tmp = (char *)s;
// 	while (i < n)
// 	{
// 		tmp[i] = '\0';
// 		i++;
// 	}
// 	return ;
// }
