/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:52:03 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/10 11:54:58 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs1(int nbr)
{
	int abs;

	return (abs = (nbr < 0 ? -nbr : nbr));
}

int	ft_dump_tokens(t_db tokens)
{
	int count;

	count = 0;
	if (tokens.flags_mask & 2)
		count += write(1, "-", 1);
	if (tokens.width >= 0)
		ft_pf_putnbr(tokens.width, &count);
	if (tokens.precision > 0)
	{
		count += write(1, ".", 1);
		ft_pf_putnbr(tokens.precision, &count);
	}
	return (count);
}
