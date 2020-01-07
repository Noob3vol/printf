#include "ft_printf.h"
#include <unistd.h>


/*
** Format processor
*/

int	pf_c(t_db tokens, void *value)
{
	char *c;

	c = (char *)value;
	return (write(1, c, 1));
}

int	pf_s(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%s:", 16));
}

int	pf_p(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%p:", 16));
}

int	pf_d(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%d:", 16));
}

int	pf_i(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%i:", 16));
}

int	pf_u(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%u:", 16));
}

int	pf_x(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%x:", 16));
}

int	pf_X(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%X:", 16));
}

void	ft_pf_putnbr(int nbr, int *count)
{
	if (nbr < -9 || nbr > 9)
		ft_pf_putnbr(nbr / 10, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

int	pf_dump_tokens(t_db tokens)
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

void	ft_init_param(t_db *param, char **str, int *i)
{
	param->flags_mask = 0;
	param->width = -1;
	param->precision = -1;
	*str = &((*str)[*i]);
	i = 0;
}

int	ft_printf(char *str, ...)
{
	int 	i;
	int	count;
	int	ret;
	t_db	param;
	va_list ap;

	i = 0;
	count = 0;
	ret = 0;
	va_start(ap ,str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += write(1, str, i++);
			ft_init_param(&param, &str, &i);
			ft_handle_flags(&str, &param);
			ft_handle_field(&str, &param, &ap);
			if (!(ret = ft_handle_format(*(str++), param, &ap)))
				return (-1);
			count += ret;
		}
		else
			i++;
	}
	va_end(ap);
	count += write(1, str, i);
	return (count);
}

int	main(void)
{
		ft_printf("Hello%      % World !");
		return (0);
}
