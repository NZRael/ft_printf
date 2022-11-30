/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:08:15 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/30 13:18:02 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_arguments(s[i + 1], arg, &count);
			i++;
		}
		else
			ft_putchar_fd(s[i], 1, &count);
		i++;
	}
	va_end(arg);
	return (count);
}
/*
int	main()
{
	printf("%i\n", printf("%p\n", (void *)-14523));
	ft_printf("%i\n", ft_printf("%p\n", (void *)-14523));
}*/
