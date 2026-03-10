/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:58:57 by fadzejli          #+#    #+#             */
/*   Updated: 2025/05/04 14:21:19 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(char format, unsigned long nbr, int *len)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_puthex(format, nbr / 16, len);
		ft_puthex(format, nbr % 16, len);
	}
	else
		ft_putchar(base[(unsigned int)nbr], len);
}

void	ft_putptr(void *ptr, int *len)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (!addr)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_puthex('x', addr, len);
}
