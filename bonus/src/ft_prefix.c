#include "ft_printf.h"

int	ftpf_padding_left(t_format fmt)
{
	int count;

	if (fmt.msk_flag & ftpf_is_mask("-0"))
		return (0);
	count = 0;
	while (fmt.field > fmt.preci)
	{
		count += write(1, " ", 1);
		fmt.field--;
	}
	return (count);
}

int	ftpf_padding_0(t_format fmt)
{
	int count;

	if ((fmt.msk_flag & ftpf_is_msk("-0")) != ftpf_is_flag('0'))
		return (0);
	count = 0;
	while (fmt.field > fmt.preci)
	{
		count += write(1, "0", 1);
		fmt.field--;
	}
	return (count);
}

int	ftpf_prefix_i(t_format fmt)
{
	if (type == 'i')
	{
		
	}
}
