/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduchang <dduchang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:33:17 by dduchang          #+#    #+#             */
/*   Updated: 2022/07/10 15:19:42 by dduchang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			c = 'C';
	char			s[] = "String";
	//void			*p = NULL;
	int				d = 12345;
	int				i = 54321;
	unsigned int	u = 123456789;
	unsigned int			x = 0x2a;
	unsigned int			X = 0x2A;
/*	
	ft_printf("Character: %c", c);
	ft_printf("\n");
	ft_printf("String of charracters: %s", s);
	ft_printf("\n");
	ft_printf("Pointer addresse: %p", p);
	ft_printf("\n");
	ft_printf("Signed decimal integer d: %d", d);
	ft_printf("\n");
	ft_printf("Signed decimal integer i: %i", i);
	ft_printf("\n");
	ft_printf("Unsigned decimal integer: %u", u);
	ft_printf("\n");
	ft_printf("Unsigned hexadecimal integer: %x", x);
	ft_printf("\n");
	ft_printf("Unsigned hexadecimal integer: %X", X);
	ft_printf("\n");
	ft_printf("Pourcent: %%");
	ft_printf("\n");
	ft_printf("\n");
*/
	printf("Printed bytes = %d\n\n", ft_printf("Og printf: %c | %s | %p | %d | %i | %u | %x | %X | %%\n", c, s, &c, d, i, u, x, X));
	printf("Printed bytes = %d\n", ft_printf("My printf: %c | %s | %p | %d | %i | %u | %x | %X | %%\n", c, s, &c, d, i, u, x, X));
	return (0);
}
