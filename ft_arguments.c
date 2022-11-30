/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:35:05 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/30 10:19:12 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(int n, char *base, int *count)
{
	int	size;

	size = ft_strlen(base);
	if (n >= size)
	{
		ft_puthex(n / size, base, count);
		ft_puthex(n % size, base, count);
	}
	else
	{
		ft_putchar_fd(base[n], 1, count);
		count++;
	}
}

static void	ft_putadress(void *arg, int *count)
{
	unsigned int	adr;
	char			*base;
	char			ptr[12];
	int				i;

	adr = (unsigned int)arg;
	base = "0123456789abcdef";
	i = 11;
	while (((adr / 16) > 0) || (i >= 11))
	{
		ptr[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	ptr[i] = base[(adr % 16)];
	ft_putstr_fd("0x", 1, count);
	while (i < 12)
	{
		write(1, &ptr[i++], 1);
		*count += 1;
	}
	return ;
}

void	ft_arguments(char str, va_list arg, int *count)
{
	if (str == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, count);
	else if (str == 's')
		ft_putstr_fd(va_arg(arg, char *), 1, count);
	else if (str == 'p')
		ft_putadress(va_arg(arg, void *), count);
	else if (str == 'i' || str == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1, count);
	else if (str == 'x')
		ft_puthex(va_arg(arg, int), "0123456789abcdef", count);
	else if (str == 'X')
		ft_puthex(va_arg(arg, int), "0123456789ABCDEF", count);
}
