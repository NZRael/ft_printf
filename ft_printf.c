/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:08:15 by sboetti           #+#    #+#             */
/*   Updated: 2022/12/01 12:26:05 by sboetti          ###   ########.fr       */
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
	printf("%i\n", printf("8F?~'?nA%p$>;.%cY%crA\%iZ^&(@lVC;_",
(void *)-4916737015674609125, -973327128, 1983244599, -539903808));
	ft_printf("%i\n", ft_printf("8F?~'?nA%p$>;.%cY%crA\%iZ^&(@lVC;_",
(void *)-4916737015674609125, -973327128, 1983244599, -539903808));
}*/
