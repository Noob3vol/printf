/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:11:55 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/11 14:13:40 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int nbr, int len, int *count)
{
	if (nbr < -9 || nbr > 9 || len > 1)
		ft_putnbr_len(nbr / 10, len - 1, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len_u(unsigned int nbr, int len, int *count)
{
	if (nbr > 9 || len > 1)
		ft_putnbr_len(nbr / 10, len - 1, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len_x(unsigned int nbr, int len, int *count)
{
	if (nbr > 15 || len > 1)
		ft_putnbr_len_x(nbr / 16, len - 1, count);
	*count += write(1, &"0123456789abcdef"[(ft_abs(nbr % 16))], 1);
}

void	ft_putnbr_len_p(unsigned long nbr, int len, int *count)
{
	if (nbr > 15 || len > 1)
		ft_putnbr_len_p(nbr / 16, len - 1, count);
	*count += write(1, &"0123456789abcdef"[(ft_abs(nbr % 16))], 1);
}

void	ft_putnbr_len_hex(unsigned int nbr, int len, int *count)
{
	if (nbr > 15 || len > 1)
		ft_putnbr_len_hex(nbr / 16, len - 1, count);
	*count += write(1, &"0123456789ABCDEF"[(ft_abs(nbr % 16))], 1);
}

void	ft_putnbr_len_f(double nbr, int len, int *count)
{
	long nbr_i;

	ft_putnbr_len((nbr_i = (long)nbr), 0, count);
	if (len > 0)
	{
		*count += write(1, ".", 1);
		nbr = nbr - (double)nbr_i;
		while (len > 1)
		{
			nbr *= 10;
			ft_putnbr_len((long)nbr, 0, count);
			nbr -= (int)nbr;
			len--;
		}
		nbr *= 10;
		if ((nbr - (int)nbr) >= 0.5 || (nbr - (int)nbr) <= -0.5)
			nbr = (nbr < 0 ? nbr - 1 : nbr + 1);
		ft_putnbr_len((long)nbr, 0, count);
	}
}
