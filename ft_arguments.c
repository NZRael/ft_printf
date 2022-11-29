/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:10:53 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/29 11:50:21 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putadress(void *arg)
{
	unsigned long	adr;
	char			*base;
	char			ptr[12];
	int				i;

	adr = (unsigned long)arg;
	base = "0123456789abcdef";
	i = 11;
	while (((adr / 16) > 0) || (i >= 11))
	{
		ptr[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	ptr[i] = base[(adr % 16)];
	ft_putstr_fd("0x", 1);
	while (i < 12)
		write(1, &ptr[i++], 1);
	return ;
}

const char	*ft_arguments(const char *str, va_list arg)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (*str == 'd')
		ft_putd(va_arg(arg, int));
	else if (*str == 's')
	{
		if (!va_arg(arg, char *))
			ft_putstr_fd("(null)", 1);
		else
			ft_putstr_fd(va_arg(arg, char *), 1);
	}
	else if (*str == 'p')
		ft_putadress(va_arg(arg, void *));
	else if (*str == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else
		return (0);
	str++;
	return (str);
}
