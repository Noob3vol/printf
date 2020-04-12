#include "ft_printf.h"

int	ftpf_ruler_i(int nbr, t_format fmt)
{
	int nbrlen;
	int neg;

	if (!nbr && !fmt.preci)
		return (0);
	nbrlen = 1;
	neg = (nbr < 0 ? 1 : 0);
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		nbrlen++;
	}
	if (fmt.preci > nbrlen)
		return (fmt.preci + neg);
	return (nbrlen + neg);
}

int	ftpf_ruler_u(unsigned int nbr, t_format fmt)
{
	int nbrlen;

	if (!nbr && !fmt.preci)
		return (0);
	nbrlen = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		nbrlen++;
	}
	if (fmt.preci > nbrlen)
		return (fmt.preci);
	return (nbrlen);
}

int	ftpf_ruler_x(unsigned int nbr, t_format fmt)
{
	int nbrlen;

	if (!nbr && !fmt.preci)
		return (0);
	nbrlen = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbrlen++;
	}
	if (fmt.preci > nbrlen)
		return (fmt.preci);
	return (nbrlen);
}

int	ftpf_ruler_p(unsigned long nbr, t_format fmt)
{
	int nbrlen;

	if (!nbr && !fmt.preci)
		return (5);
	nbrlen = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		nbrlen++;
	}
	if (fmt.preci > nbrlen)
		return (fmt.preci);
	fmt.preci += 2;
	return (nbrlen);
}

int	ftpf_ruler_s(char *str, t_format fmt)
{
	if (!str)
		return (6);
	if (ft_strlen(str) < fmt.preci)
		return (ft_strlen(str);
	return (fmt.preci);
}
