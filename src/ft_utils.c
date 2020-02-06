#include "ft_printf.h"

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

int	ft_abs(int nbr)
{
	int abs;

	return (abs = (nbr < 0 ? -nbr : nbr));
}

int	ft_dump_tokens(t_db tokens)
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

int	ft_nbrlen(int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr < -9 || nbr > 9)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_u(unsigned int nbr)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_x(unsigned int nbr)
{
	int nbr_len;
	
	nbr_len = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_nbrlen_base(int nbr, int base)
{
	int nbr_len;

	nbr_len = 1;
	while (nbr < -(base - 1) || nbr > (base - 1))
	{
		nbr /= base;
		nbr_len++;
	}
	return (nbr_len);
}
