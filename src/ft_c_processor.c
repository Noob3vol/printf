#include "ft_printf.h"

int	ft_is_flag(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int	ft_is_field(char c)
{
	if ((c >= '0' && c <= '9') || c == '*' || c == '.')
		return (1);
	return (0);
}

int	ft_is_format(char c)
{
	char 	formats[] = FORMAT;
	int	i;

	i = 0;
	while (formats[i])
	{
		if (c == formats[i])
			return (i);
		i++;
	}
	return (-1);
}
