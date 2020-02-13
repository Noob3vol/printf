/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ruler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:02:32 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 05:04:06 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr < -9 || nbr > 9)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_u(unsigned int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_x(unsigned int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_p(unsigned long nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbr_len++;
	}
	return (nbr_len);
}

/*
**	int	ft_nbrlen_base(int nbr, int base)
**	{
**		int nbr_len;
**
**		nbr_len = 1;
**		while (nbr < -(base - 1) || nbr > (base - 1))
**		{
**			nbr /= base;
**			nbr_len++;
**		}
**		return (nbr_len);
**	}
*/
