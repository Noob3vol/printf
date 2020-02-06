#define ABS(x) ((x) < 0 ? -1 * (x) : (x))
#include <unistd.h>

static int	ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (base[i] == '-' || base[i] == '+')
		return (0);
	while (base[i + 1])
	{
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
			if (base[j] == '-' || base[j] == '+')
				return (0);
		}
		i++;
	}
	if (j < 3)
		return (0);
	return (j);
}

static void	ft_recurse_putbase(int nbr, char *base, int base_len)
{
	if (nbr < -base_len || nbr > base_len)
		ft_recurse_putbase(nbr / base_len, base, base_len);
	write(1, &base[ABS(nbr % base_len)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;


	if (!(base_len = ft_check_base(base)))
	{
		write(1, "Error, bad base", 15);
		return ;
	}
	if (nbr < 0)
		write(1, "-", 1);
	ft_recurse_putbase(nbr, base, base_len);
}

/*
**	int	main(void)
**	{
**		int base_l;
**		char base[16];
**	
**		base_l = 0;
**		while (base_l < 16)
**		{
**			base[base_l] = (base_l > 9 ? base_l - 10 + 'a' : base_l + '0');
**			base[base_l + 1] = '\0';
**			ft_putnbr_base(-2147483648, base);
**			write(1, "\n", 1);
**			base_l++;
**		}
**		return (0);
**	}
*/
