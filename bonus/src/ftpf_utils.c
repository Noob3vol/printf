#include <ft_printf.h>

char	ftpf_is_flag(char c)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (c == FLAGS[i])
			return (1 << i);
		i++;
	}
	return (0);
}

char	ftpf_is_mask(char *str)
{
	char ret;
	char mask;

	mask = 0;
	while (*str)
	{
		if ((ret = ftpf_is_flag(*str)))
			mask |= ret;
		str++;
	}
	return mask;
}
