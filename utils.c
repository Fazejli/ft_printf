/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:48:16 by fadzejli          #+#    #+#             */
/*   Updated: 2025/04/30 15:02:32 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		*len += 1;
		i++;
	}
}

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	else if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}

void	ft_unsigned_putnbr(unsigned int nbr, int *len)
{
	if (nbr < 0)
	{
		write(1, "4294967295", 10);
		*len += 10;
		return ;
	}
	if (nbr > 9)
	{
		ft_unsigned_putnbr(nbr / 10, len);
		ft_unsigned_putnbr(nbr % 10, len);
	}
	else
		ft_putchar(nbr + 48, len);
}
