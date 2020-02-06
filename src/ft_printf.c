#include "ft_printf.h"
#include <unistd.h>


/*
** Format processor
*/

int	pf_c(t_db tokens, int value)
{
	int count;
	char c;

	count = 0;
	c = (char)value;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, 1);
	count += write(1, &c, 1);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > 0)
			count += write(1, " ", 1);
	return (count);
}

int	pf_s(t_db tokens, char *str)
{
	int count;
	int print_len;
	char nul[] = "(null)";

	count = 0;
	if (!str)
		str = nul;
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


int	pf_p(t_db tokens, char *value)
{
	int count;
	int print_len;
	unsigned int nbr;

	count = 0;
	nbr = (unsigned int)value;
	print_len = ft_nbrlen_x(nbr);
	if (tokens.precision > print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len + 2);
	count += write (1, "0x", 2);
	ft_putnbr_len_x(nbr, print_len, &count);
	print_len += 2;
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int	pf_i(t_db tokens, int nbr)
{
	int count;
	int print_len;

	count = 0;
	print_len = ft_nbrlen(nbr);
	if (tokens.precision >= print_len)
		print_len = tokens.precision;
	if (nbr < 0)
		print_len++;
	if (!(tokens.flags_mask & 3))
		count += pf_left_paggin(&tokens, print_len);
	if (nbr < 0)
		count += write(1, "-", 1);
	if ((tokens.flags_mask & 3) == 1)
		count += pf_left_paggin(&tokens, print_len);
	if (nbr < 0)
		print_len--;
	ft_putnbr_len(nbr, print_len, &count);
	if (nbr < 0)
		print_len++;
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int	pf_d(t_db tokens, int nbr)
{
	return (pf_i(tokens, nbr));
}

int	pf_u(t_db tokens, int value)
{
	unsigned int nbr;
	int count;
	int print_len;

	nbr = (unsigned int)value;
	count = 0;
	print_len = ft_nbrlen_u(nbr);
	if (tokens.precision > print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len);
	ft_putnbr_len_u(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int	pf_x(t_db tokens, int value)
{
	int count;
	int print_len;
	unsigned int nbr;

	count = 0;
	nbr = (unsigned int)value;
	print_len = ft_nbrlen_x(nbr);
	if (tokens.precision >= print_len)
		print_len = tokens.precision;
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len);
	ft_putnbr_len_x(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}

int	pf_X(t_db tokens, int value)
{
	int count;
	int print_len;
	unsigned int nbr;

	count = 0;
	nbr = (unsigned int)value;
	print_len = (nbr < 0 ? ft_nbrlen_x(nbr) + 1 : ft_nbrlen_x(nbr));
	if (tokens.precision >= print_len)
		print_len = (nbr < 0 ? tokens.precision + 1 : tokens.precision);
	if ((tokens.flags_mask & 3) < 2)
		count += pf_left_paggin(&tokens, print_len);
	ft_putnbr_len_hex(nbr, print_len, &count);
	if (tokens.flags_mask & 2)
		while (tokens.width-- > print_len)
			count += write(1, " ", 1);
	return (count);
}


void	ft_init_param(t_db *param, char **str, int *i)
{
	param->flags_mask = 0;
	param->width = -1;
	param->precision = -1;
	*str = &((*str)[*i]);
	*i = 0;
}

int	ft_printf(char *str, ...)
{
	int 	i;
	int	count;
	int	ret;
	t_db	param;
	va_list ap;

	if (!str)
		return (0);
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

void	test_printf_id(char *str, int nbr)
{
	setbuf(stdout, NULL);
	printf("Sample-str\t\tValue = %d\t\tValue = %d\n", nbr, -nbr);
	printf("pf    = %s\t\t|", str);
	printf(str, nbr);
	printf("|\t\t|");
	printf(str, -nbr);
	ft_putstr("|\n");
	printf("ft_pf = %s\t\t|", str);
	ft_printf(str, nbr);
	printf("|\t\t|");
	ft_printf(str, -nbr);
	ft_putstr("|\n");
}

void	test_printf_s(char *str, char *value)
{
	printf("Sample-str\t\tValue\n");
	printf("pf(%s)    \t= \t|", str);
	printf(str, value);
	printf("|\nft_pf(%s) \t= \t|", str);
	ft_printf(str, value);
	ft_putstr("|\n");
}

void	test_printf(char *str)
{
	printf("Sample-str\t\tValue\n");
	printf("pf(%s)    \t= \t|", str);
	printf(str);
	printf("|\nft_pf(%s) \t= \t|", str);
	ft_printf(str);
	ft_putstr("|\n");
}

void	test_lambda(void)
{
	test_printf(NULL);
	test_printf("");
	test_printf("Hello World");
}

void	test_i(int value)
{
	test_printf_id("%12i", value);
	test_printf_id("%012i", value);
	test_printf_id("%-12i", value);
	test_printf_id("%12.4i", value);
	test_printf_id("%-12.4i", value);
}

void	test_x(int value)
{
	test_printf_id("%12x", value);
	test_printf_id("%012x", value);
	test_printf_id("%-12x", value);
	test_printf_id("%12.4x", value);
	test_printf_id("%-12.4x", value);
}

void	test_u(int value)
{
	test_printf_id("%12u", value);
	test_printf_id("%012u", value);
	test_printf_id("%-12u", value);
	test_printf_id("%12.4u", value);
	test_printf_id("%-12.4u", value);
}

void	test_hex(int value)
{
	test_printf_id("%12X", value);
	test_printf_id("%012X", value);
	test_printf_id("%-12X", value);
	test_printf_id("%12.4X", value);
	test_printf_id("%-12.4X", value);
}

void	test_s(void)
{
	char *ref = NULL;
	char ref2[] = "Hello, World";

	test_printf_s("%s", ref);
	test_printf_s("%10s", ref);
	test_printf_s("%.10s", ref);
	test_printf_s("%-10s", ref);
	test_printf_s("%.15s", ref);
	test_printf_s("%-15s", ref);
	test_printf_s("%15.10s", ref);
	test_printf_s("%-15.10s", ref);
}

void	test_p(void)
{
	char ref[] = "Hello, World";

	test_printf_s("%p", ref);
	test_printf_s("%10p", ref);
	test_printf_s("%.10p", ref);
	test_printf_s("%-10p", ref);
	test_printf_s("%.15p", ref);
	test_printf_s("%-15p", ref);
	test_printf_s("%15.10p", ref);
	test_printf_s("%-15.10p", ref);
}

int	main(void)
{
	int ret;
	setbuf(stdout, NULL);
/*
**	test_lambda();
**	test_s();
**	test_i();
**	test_u();
**	test_x();
	test_p();
**	test_hex();
*/
//	test_i(2);
	ft_printf("%i || %% || %d", 10, - 10);
	ft_printf("%s || %% || %p", 10, - 10);


	//ft_printf("%i", 10);
/*
**	ret = printf("%12i\t", 45);
**	printf("[%d]\t", ret);
**	ft_putnbr(ret);
**	ft_putchar('\t');
**	ret = ft_printf("%12i\t", 45);
**	ft_putnbr(ret);
**	ft_putchar('\n');
**	ret = printf("%10.0i\t", -45);
**	ft_putnbr(ret);
**	ft_putchar('\n');
**	ret = ft_printf("%10.0i\t", -45);
**	ft_putnbr(ret);
**	ft_putchar('\n');
*/
	return (0);
}

/*
 *	A implémenté : pf_x, pf_X, pf_p
 *
 *	Mettre a la norme
*/
