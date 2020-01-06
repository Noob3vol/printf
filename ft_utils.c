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
