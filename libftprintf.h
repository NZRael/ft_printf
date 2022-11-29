/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:12:05 by sboetti           #+#    #+#             */
/*   Updated: 2022/11/28 15:18:22 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *s, ...);
const char	*ft_arguments(const char *str, va_list arg);

#endif
