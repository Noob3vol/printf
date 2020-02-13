/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pformat_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:50:26 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/11 16:10:34 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TEST write(1, "TEST\n", 5)

int		pf_i(t_db tokens, int nbr)
{
	int count;
	int print_len;

	count = 0;
	print_len = (!tokens.precision && !nbr ? 0 : ft_nbrlen(nbr));
	if (tokens.precision >= print_len)
		print_len = tokens.precision;
	if (nbr < 0)
		print_len++;
	if (!(tokens.flags_mask & 3) || ((tokens.flags_mask & 3) == 1 && tokens.star_count == 2))
		count += pf_left_paggin_i(&tokens, print_len);
	if (nbr < 0)
		count += write(1, "-", 1);
	if ((tokens.flags_mask & 3) == 1)
		count += pf_left_paggin_i(&tokens, print_len);
	if (nbr < 0)
		print_len--;
	if (tokens.precision || nbr)
		ft_putnbr_len(nbr, print_len, &count);
	if (nbr < 0)
		print_len++;
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int		pf_d(t_db tokens, int nbr)
{
	return (pf_i(tokens, nbr));
}

int		pf_u(t_db tokens, int value)
{
	unsigned int	nbr;
	int				count;
	int				print_len;

	nbr = (unsigned int)value;
	count = 0;
	print_len = (!tokens.precision && !nbr ? 0 : ft_nbrlen_u(nbr));
	if (tokens.precision > print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin_i(&tokens, print_len);
	if (tokens.precision || nbr)
	ft_putnbr_len_u(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int		pf_x(t_db tokens, int value)
{
	int				count;
	int				print_len;
	unsigned int	nbr;

	count = 0;
	nbr = (unsigned int)value;
	print_len = (!tokens.precision && !nbr ? 0 : ft_nbrlen_x(nbr));
	if (tokens.precision >= print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin_i(&tokens, print_len);
	if (tokens.precision || nbr)
	ft_putnbr_len_x(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int		pf_hex(t_db tokens, int value)
{
	int				count;
	int				print_len;
	unsigned int	nbr;

	count = 0;
	nbr = (unsigned int)value;
	print_len = (!tokens.precision && !nbr ? 0 : ft_nbrlen_x(nbr));
//	print_len = (nbr < 0 ? ft_nbrlen_x(nbr) + 1 : ft_nbrlen_x(nbr));
	if (tokens.precision >= print_len)
		print_len = (nbr < 0 ? tokens.precision + 1 : tokens.precision);
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin_i(&tokens, print_len);
	if (tokens.precision || nbr)
		ft_putnbr_len_hex(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}
