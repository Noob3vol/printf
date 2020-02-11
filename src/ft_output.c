/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:57:29 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/11 19:53:50 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putnbr(int nbr, int *count)
{
	if (nbr < -9 || nbr > 9)
		ft_pf_putnbr(nbr / 10, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

int		pf_left_paggin(t_db *tokens, int print_len)
{
	int		count;
	char	c_paggin;

	count = 0;
	c_paggin = ' ';
	if (tokens->flags_mask & 1)
		c_paggin = '0';
	while (tokens->width-- > print_len)
		count += write(1, &c_paggin, 1);
	return (count);
}

int		pf_left_paggin_i(t_db *tokens, int print_len)
{
	int		count;
	char	c_paggin;

	count = 0;
	c_paggin = ' ';
	if (tokens->flags_mask & 1 && !(tokens->star_count == 2))
		c_paggin = '0';
	while (tokens->width-- > print_len)
		count += write(1, &c_paggin, 1);
	return (count);
}

int		pf_left_paggin_s(t_db *tokens, int print_len)
{
	int		count;
	char	c_paggin;

	count = 0;
	c_paggin = ' ';
	while (tokens->width-- > print_len)
		count += write(1, &c_paggin, 1);
	return (count);
}

int		pf_left_paggin_1(t_db *tokens, int print_len)
{
	int		count;
	char	c_paggin;

	count = 0;
	c_paggin = ' ';
	if (tokens->flags_mask & 1)
		c_paggin = '0';
	while (tokens->width-- > print_len)
		count += write(1, &c_paggin, 1);
	return (count);
}
