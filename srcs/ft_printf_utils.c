/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:33:17 by dduchang          #+#    #+#             */
/*   Updated: 2022/07/10 15:18:52 by dduchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putaddress_len(unsigned long long nbr, char *base)
{
	unsigned long long	base_digits;
	int					len;

	len = 0;
	base_digits = 0;
	while (base[base_digits])
		base_digits++;
	if (nbr < base_digits)
		len += ft_putchar_len(base[nbr]);
	else
	{
		len += ft_putnbrbase_len(nbr / base_digits, base);
		len += ft_putnbrbase_len(nbr % base_digits, base);
	}
	return (len);
}

int	ft_putnbrbase_len(long long nbr, char *base)
{
	long long	base_digits;
	int			len;

	len = 0;
	base_digits = 0;
	while (base[base_digits])
		base_digits++;
	if (nbr < 0)
	{
		len += ft_putchar_len('-');
		nbr *= -1;
	}
	if (nbr < base_digits)
		len += ft_putchar_len(base[nbr]);
	else
	{
		len += ft_putnbrbase_len(nbr / base_digits, base);
		len += ft_putnbrbase_len(nbr % base_digits, base);
	}
	return (len);
}

int	ft_putstr_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

int	ft_putchar_len(char c)
{
	return (write(1, &c, 1));
}
