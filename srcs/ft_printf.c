/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:33:17 by dduchang          #+#    #+#             */
/*   Updated: 2022/07/10 15:19:14 by dduchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static void	distributor(va_list ap, const char *fmt, int *len, char *str)
{
	if (*fmt == '%')
		*len += ft_putchar_len('%');
	else if (*fmt == 'd' || *fmt == 'i')
		*len += ft_putnbrbase_len(va_arg(ap, int), "0123456789");
	else if (*fmt == 'u')
		*len += ft_putnbrbase_len(va_arg(ap, unsigned int), "0123456789");
	else if (*fmt == 'x')
		*len += ft_putnbrbase_len(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (*fmt == 'X')
		*len += ft_putnbrbase_len(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (*fmt == 'c')
		*len += ft_putchar_len(va_arg(ap, int));
	else if (*fmt == 'p')
	{
		*len += ft_putstr_len("0x");
		*len += ft_putaddress_len(va_arg(ap, unsigned long long),
								"0123456789abcdef");
	}
	else if (*fmt == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			*len += ft_putstr_len("(null)");
		else
			*len += ft_putstr_len(str);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;
	char	*str;

	va_start(ap, fmt);
	len = 0;
	str = NULL;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			distributor(ap, fmt, &len, str);
		}
		else
			len += ft_putchar_len(*fmt);
		fmt++;
	}
	va_end(ap);
	return (len);
}
