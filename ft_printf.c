/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:50:34 by fadzejli          #+#    #+#             */
/*   Updated: 2025/06/03 14:57:21 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unit_print(const char format, va_list list, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(list, int), len);
	else if (format == 's')
		ft_putstr(va_arg(list, char *), len);
	else if (format == 'p')
		ft_putptr(va_arg(list, void *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(list, int), len);
	else if (format == 'u')
		ft_unsigned_putnbr(va_arg(list, unsigned int), len);
	else if (format == 'x' || format == 'X')
		ft_puthex(format, va_arg(list, unsigned int), len);
	else if (format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			unit_print(format[i + 1], list, &len);
			i++;
		}
		else if (format[i] == '%' && !format[i + 1])
		{
			write(2, "ERROR\n", 7);
			return (-1);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(list);
	return (len);
}
