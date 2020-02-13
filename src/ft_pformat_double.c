/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pformat_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:58:13 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/10 12:15:21 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_f(t_db tokens, double nbr)
{
	int count;
	int print_len;
	int nbr_len;

	if (tokens.precision == -1)
		tokens.precision = 6;
	count = 0;
	nbr_len = ft_nbrlen((int)nbr);
	print_len = (!tokens.precision ? 0 : tokens.precision + 1);
	if (nbr < 0.0)
		print_len++;
	if (!(tokens.flags_mask & 3))
		count += pf_left_paggin(&tokens, print_len + nbr_len);
	if (nbr < 0.0)
		count += write(1, "-", 1);
	if ((tokens.flags_mask & 3) == 1)
		count += pf_left_paggin(&tokens, print_len + nbr_len);
	if (nbr < 0.0)
		print_len--;
	ft_putnbr_len_f(nbr, tokens.precision, &count);
	if (nbr < 0.0)
		print_len++;
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len + nbr_len)
			count += write(1, " ", 1);
	return (count);
}
