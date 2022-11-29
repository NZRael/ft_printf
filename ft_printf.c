/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:08:15 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/29 10:49:51 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ... )
{
	int		i;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			s = ft_arguments(&s[i + 1], arg);
//		else
//			s = ft_read();
		i++;
	}
	va_end(arg);
	return (0);
}
