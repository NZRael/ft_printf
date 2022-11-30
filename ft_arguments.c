/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:35:05 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/30 12:59:16 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putu(unsigned int n, int *count)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1, count);
		ft_putnbr_fd(n * -1, 1, count);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, 1, count);
		ft_putnbr_fd(n % 10, 1, count);
	}
	else
		ft_putchar_fd('0' + n, 1, count);
}

static void	ft_puthex(unsigned int n, char *base, int *count)
{
	unsigned int	size;

	size = 16;
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

static void	ft_putadress(unsigned long long arg, int *count)
{
	unsigned long long	adr;
	const char			*base;
	char				ptr[12];
	int					i;

	adr = arg;
	base = "0123456789abcdef";
	i = 11;
	while ((adr / 16) > 0)
	{
		ptr[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	ptr[i] = base[(adr % 16)];
	ft_putstr_fd("0x", 1, count);
	while (i < 12)
	{
		ft_putchar_fd(ptr[i], 1, count);
		i++;
	}
}

void	ft_arguments(char str, va_list arg, int *count)
{
	char	*vaa;

	if (str == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, count);
	else if (str == 's')
	{
		vaa = va_arg(arg, char *);
		if (!vaa)
			ft_putstr_fd("(null)", 1, count);
		else
			ft_putstr_fd(vaa, 1, count);
	}
	else if (str == 'p')
		ft_putadress(va_arg(arg, unsigned long long), count);
	else if (str == 'i' || str == 'd')
		ft_putnbr_fd(va_arg(arg, int), 1, count);
	else if (str == 'u')
		ft_putu(va_arg(arg, unsigned int), count);
	else if (str == 'x')
		ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef", count);
	else if (str == 'X')
		ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
	else if (str == '%')
		ft_putchar_fd('%', 1, count);
}
