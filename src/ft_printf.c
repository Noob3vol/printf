#include "ft_printf.h"
#include <unistd.h>


/*
** Format processor
*/

int	ft_nbrlen(int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr < -9 || nbr > 9)
		nbr /= 10;
	return (nbr_len);
}

void	ft_pf_putnbr(int nbr, int *count)
{
	if (nbr < -9 || nbr > 9)
		ft_pf_putnbr(nbr / 10, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len(int nbr, int len, int *count)
{
	if (nbr < -9 || nbr > 9 || len > 0)
		ft_putnbr_len(nbr / 10, len - 1, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

int	pf_left_paggin(t_db *tokens, int print_len)
{
	int count;
	char c_paggin;
	
	count = 0;
	c_paggin = ' ';
	if (tokens->flags_mask & 1)
		c_paggin = '0';
	while (tokens->width-- > print_len)
		count += write(1, &c_paggin, 1);
	return (count);
}

int	pf_c(t_db tokens, void *value)
{
	int count;
	char *c;

	count = 0;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, 1);
	c = (char *)value;
	count += write(1, c, 1);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > 0)
			count += write(1, " ", 1);
	return (count);
}

int	pf_s(t_db tokens, void *value)
{
	int count;
	int print_len;
	char *str;

	count = 0;
	str = (char *)value;
	print_len = ft_strlen(str);
	if (tokens.precision != -1 && tokens.precision < print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len);
	count += write(1, str, print_len);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int	pf_p(t_db tokens, void *value)
{
	int	count;
	int	*nbr;

	count = 0;
	nbr = (int *)value;
	return (write(1, ":ToImplement%p:", 16));
}

int	pf_d(t_db tokens, void *value)
{
	return (write(1, ":ToImplement%d:", 16));
}

int	pf_i(t_db tokens, void *value)
{
	int count;
	int print_len;
	int *nbr;

	count = 0;
	nbr = (int *)value;
	print_len = ft_nbrlen(*nbr);
	if (tokens.precision > print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len);
	if (*nbr < 0)
		count += write(1, "-", 1);
	ft_putnbr_len(*nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
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

#include <stdio.h>

void	test_ft_printf_compare(char *str, ...)
{
	int ret;
	va_list lol;

	setbuf(stdout, NULL);
	va_start(lol, str);
	printf("reférence string : %s\n", str);
	printf("prinft output \"");
	ret = printf(str, lol);
	printf("\t[%d]\n", ret);
	printf("ft_prinft output \"");
	ret = ft_printf(str, lol);
	printf("\"\t[%d]\n", ret);
	va_end(lol);
}

void	test_pf_s(void)
{
	int ret;

	ret = printf("Hello% 0*.*s World !\t", 10, 20, "You !");
	fflush(stdout);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ret = ft_printf("Hello%0*.*s World !\t", 10, 20, "You !");
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ret = printf("Hello%-0*.*s World !\t", 10, 20, "You !");
	fflush(stdout);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ret = ft_printf("Hello%-0*.*s World !\t", 10, 20, "You !");
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
}

void	test_pf_p(void)
{
	int ret;
	void *addr;
	long addr_trlt;

	addr_trlt = (long)addr;
	ret = printf("Hello%p World !\t", addr);
	fflush(stdout);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ft_putnbr_base(("0123456789abcdef" ,(unsigned int)addr));
	ret = ft_printf("Hello%p World !\t", addr);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ret = printf("Hello%p World !\t", addr);
	fflush(stdout);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
	ret = ft_printf("Hello%p World !\t", addr);
	ft_putchar(':');
	ft_putnbr(ret);
	ft_putstr(":\n");
}

void	test_pf_i(void)
{
	int ret;

}
	

int	main(void)
{
//	test_pf_s();
//	test_pf_p();
	test_ft_printf_compare("hello%c", '!');
	return (0);
}

	/*
	**	while (ft_is_format(*str) == -1 && *str != '%')
	**	{
	**		if (!str)
	**			return (-1);
	**		str++;
	**	}
	*/
