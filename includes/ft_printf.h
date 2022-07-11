/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:16:20 by dduchang          #+#    #+#             */
/*   Updated: 2022/07/11 10:31:40 by dduchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

// Prototypes
int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int	ft_putaddress_len(unsigned long long nbr, char *base);
int	ft_putnbrbase_len(long long nbr, char *base);
int	ft_putstr_len(char *s);
int	ft_putchar_len(char c);

#endif
