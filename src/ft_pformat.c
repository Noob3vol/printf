/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:49:04 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/12 13:12:46 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_c(t_db tokens, int value)
{
	int		count;
	char	c;

	count = 0;
	c = (char)value;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, 1);
	count += write(1, &c, 1);
	if (tokens.flags_mask & 2)
		while (--tokens.width > 0)
			count += write(1, " ", 1);
	return (count);
}

int		pf_s(t_db tokens, char *str)
{
	int			count;
	int			print_len;
	static char	nul[] = "(null)";

	count = 0;
	if (!str)
		str = nul;
	print_len = ft_strlen(str);
	if (tokens.precision > -1 && tokens.precision < print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin_1(&tokens, print_len);
	count += write(1, str, print_len);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int		pf_p(t_db tokens, char *value)
{
	int				count;
	int				print_len;
	unsigned long	nbr;

	count = 0;
	nbr = (unsigned long)value;
	print_len = (!nbr && !tokens.precision ? 0 :ft_nbrlen_p(nbr));
	if (tokens.precision > print_len)
		print_len = tokens.precision;
	if (!(tokens.flags_mask & 3) || (((tokens.flags_mask & 3) == 1)  && tokens.star_count == 2))
		count += pf_left_paggin_s(&tokens, print_len + 2);
	count += write(1, "0x", 2);
	if ((tokens.flags_mask & 3) == 1)
		count += pf_left_paggin(&tokens, print_len + 2);
	if (nbr || tokens.precision)
		ft_putnbr_len_p((unsigned long)nbr, print_len, &count);
	print_len += 2;
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}
