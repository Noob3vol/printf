#include "ft_printf.h"

void	ft_pf_putnbr(int nbr, int *count)
{
	if (nbr < -9 || nbr > 9)
		ft_pf_putnbr(nbr / 10, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len(int nbr, int len, int *count)
{
	if (nbr < -9 || nbr > 9 || len > 1)
		ft_putnbr_len(nbr / 10, len - 1, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len_u(unsigned int nbr, int len, int *count)
{
	if (nbr > 9 || len > 1)
		ft_putnbr_len(nbr / 10, len - 1, count);
	*count += write(1, &"0123456789"[(ft_abs(nbr % 10))], 1);
}

void	ft_putnbr_len_x(unsigned int nbr, int len, int *count)
{
	if (nbr > 15 || len > 1)
		ft_putnbr_len_x(nbr / 16, len - 1, count);
	*count += write(1, &"0123456789abcdef"[(ft_abs(nbr % 16))], 1);
}

void	ft_putnbr_len_hex(unsigned int nbr, int len, int *count)
{
	if (nbr > 15 || len > 1)
		ft_putnbr_len_hex(nbr / 16, len - 1, count);
	*count += write(1, &"0123456789ABCDEF"[(ft_abs(nbr % 16))], 1);
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
