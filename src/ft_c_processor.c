/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:51:01 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/07 05:03:51 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int	ft_is_field(char c)
{
	if ((c >= '0' && c <= '9') || c == '*' || c == '.')
		return (1);
	return (0);
}

int	ft_is_format(char c, char *formats)
{
	int		i;

	i = 0;
	while (formats[i])
	{
		if (c == formats[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_pf_atoi(char **str)
{
	int	nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		nbr *= 10;
		nbr += (**str) - '0';
		++(*str);
	}
	return (nbr);
}
