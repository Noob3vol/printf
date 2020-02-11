/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:44:57 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/11 15:10:29 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_param(t_db *param, char **str, int *i)
{
	param->flags_mask = 0;
	param->width = -1;
	param->precision = -1;
	*str = &((*str)[*i]);
	*i = 0;
	param->star_count = 0;
}

int		ft_start_handler(char **str, t_db *param, va_list *ap, int *i)
{
	int	*value;

	ft_init_param(param, str, i);
	ft_handle_flags(str, param);
	ft_handle_field(str, param, ap);
	if (**str == 'n')
	{
		value = va_arg(*ap, int *);
		*value = param->count;
		(*str)++;
		return (0);
	}
	return (ft_handle_format(*((*str)++), *param, ap));
}

void	ft_init_var(int *i, int *count, int *ret)
{
	*i = 0;
	*count = 0;
	*ret = 0;
}

int		ft_printf(char *str, ...)
{
	int		i;
	int		ret;
	t_db	param;
	va_list	ap;

	if (!str)
		return (0);
	ft_init_var(&i, &param.count, &ret);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			param.count += write(1, str, i++);
			if ((ret = ft_start_handler(&str, &param, &ap, &i)) == -1)
				return (-1);
			param.count += ret;
		}
		else
			i++;
	}
	va_end(ap);
	param.count += write(1, str, i);
	return (param.count);
}
