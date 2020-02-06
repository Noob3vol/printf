#include "ft_printf.h"

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

void	ft_get_field(char **str, int *field, va_list *fields)
{
	if (ft_isdigit((int)**str) || **str == '*')
	{
		if (ft_isdigit((int)**str))
			field = ft_pf_atoi(str);
		else
		{
			field = va_arg(*fields, int);
			(*str)++;
		}
	}
}


void	ft_handle_field(char **str, t_db *param, va_list *fields)
{
	ft_get_field(str, param.width, fields);
	if ((**str == '.'))
	{
		if ((*str)[-1] == '0' && param->width == -1)
			param->width = 0;
		param->precision = 0;
		(*str)++;
		ft_get_field(str, param.precision, fields);
	}
}

/*
 **	void	ft_get_value(char c, va_list *arg, void **ptr)
 **	{
 **		unsigned int	uvalue;
 **		int		ivalue;
 **		double		dvalue;
 **		char		*svalue;
 **	
 **		if (c == 'd' || c == 'i' || c == 'x' || c == 'X' || c == 'c')
 **		{
 **			ivalue = va_arg(*arg, int);
 **			*ptr = (void *)&ivalue;
 **		}
 **		else if (c == 'u')
 **		{
 **			uvalue = va_arg(*arg, unsigned int);
 **			*ptr = (void *)&uvalue;
 **		}
 **		else if (c == 's')
 **		{
 **			svalue = va_arg(*arg, char *);
 **			*ptr = (void *)svalue;
 **		}
 **	}
 */

int	ft_handle_format(char c, t_db param, va_list *arg)
{
	int	ret;
	int	(*fntab[])(t_db, int) = 
	{
		&pf_c, &pf_d, 
		&pf_i, &pf_u, 
		&pf_x, &pf_X,
	};

	if (!c)
		return (-1);
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'p')
		return (pf_p(param, va_arg(*arg, char *)));
	if (c == 's')
		return (pf_s(param, va_arg(*arg, char *)));
	if ((ret = ft_is_format(c)) == -1)
	{
		ret = ft_dump_tokens(param);
		return (ret += write(1, &c, 1));
	}
	return (fntab[ret](param, (va_arg(*arg, int))));
}
