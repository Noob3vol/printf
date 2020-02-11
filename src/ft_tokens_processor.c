/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_processor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:15:52 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/11 15:41:50 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define	TEST write(1, "TEST\n", 5);

void	ft_handle_flags(char **str, t_db *param)
{
	while (ft_is_flag(**str))
	{
		if (**str == '0')
			param->flags_mask |= 1;
		if (**str == '-')
			param->flags_mask |= 2;
		(*str)++;
	}
}

int		ft_get_field(char **str, va_list *fields)
{
		int field;

		if (**str == '*')
		{
			field = va_arg(*fields, int);
			(*str)++;
		}
		else 
			field = ft_pf_atoi(str);
		return (field);
}

void	ft_handle_field(char **str, t_db *param, va_list *fields)
{
	int field;

	if (**str == '*')
		param->star_count++;
	if ((field = ft_get_field(str, fields)) < 0)
		param->flags_mask |= 2;
	param->width = (field < 0 ? -field : field);
	if (**str == '.')
	{
		param->precision = 0;
		(*str)++;
		if (**str == '*')
			param->star_count++;
	if ((field = ft_get_field(str, fields)) < 0)
		param->star_count--;
		param->precision = field;
	}
}

int		ft_handle_format(char c, t_db param, va_list *arg)
{
	int			ret;
	static int	(*fntab[])(t_db, int) = {&pf_c, &pf_d, &pf_i, &pf_u,
										&pf_x, &pf_hex};

	if (!c)
		return (-1);
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'p')
		return (pf_p(param, va_arg(*arg, char *)));
	if (c == 's')
		return (pf_s(param, va_arg(*arg, char *)));
	if (c == 'f')
		return (pf_f(param, va_arg(*arg, double)));
	if ((ret = ft_is_format(c, FORMAT)) == -1)
	{
		ret = ft_dump_tokens(param);
		return (ret += write(1, &c, 1));
	}
	return (fntab[ret](param, (va_arg(*arg, int))));
}
