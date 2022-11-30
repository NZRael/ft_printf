/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:22 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/30 10:12:40 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd, int *count)
{
	int	i;

	if (!str)
		i = 0;
	else
	{
		i = 0;
		while (str[i])
		{
			ft_putchar_fd(str[i], fd, count);
			i++;
		}
		ft_putchar_fd('\n', fd, count);
	}
}
