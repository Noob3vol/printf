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

void	ft_handle_field(char **str, t_db *param, va_list *fields)
{
	char b_dot;

	b_dot = 0;
	while (ft_is_field(**str))
	{
		if ((b_dot && (**str == '.' || param->precision >= 0)) 
				|| (**str == '*' && !b_dot && param->width >= 0))
			return ;
		if ((b_dot = (**str == '.')))
		{
			if (*str[-1] == '0')
				param->width = 0;
			param->precision = 0;
			(*str)++;
		}
		if (((**str >= '0' && **str <= '9')))
		{
			if (b_dot)
				param->precision = ft_pf_atoi(str);
			else
				param->width = ft_pf_atoi(str);
		}
		else	if(**str == '*')
		{
			if (b_dot)
				param->precision = va_arg(*fields, int);
			else
				param->width = va_arg(*fields, int);
			(*str)++;
		}
	}
}

int	ft_handle_format(char c, t_db param, va_list *arg)
{
	int	ret;
	int	value;
	void	*ptr;
	int	(*fntab[])(t_db, void *) = 
	{
		&pf_c,
		&pf_s, 
		&pf_p, 
		&pf_d, 
		&pf_i, 
		&pf_u, 
		&pf_x, 
		&pf_X,
	};

	if (!c)
		return (-1);
	if (c == '%')
		return (write(1, "%", 1));
	if ((ret = ft_is_format(c)) == -1)
	{
		ret = ft_dump_tokens(param);
		return (ret += write(1, &c, 1));
	}
	value = va_arg(*arg, int);
	ptr = &value;
	return (fntab[ret](param, ptr));
}
