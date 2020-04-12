#include "ft_printf.h"

char		ftpf_get_flags(const char **str)
{
	int ret;
	char msk;

	msk = 0;
	while ((ret = ftpf_is_flag(**str)))
	{
		msk |= ret;
		(*str)++;
	}
	return (msk);
}

int		ftpf_get_fields(const char **str, va_list arg)
{
	int field;

	field = 0;
	if (**str == '*')
	{
		field = va_arg(arg, int);
	}
	else
	{
		while (**str >= '0' && **str <= '9')
		{
			field *= 10;
			field += **str - '0';
			(*str)++;
		}
	}
	return (field);
}

/*
**	Size still need to get implemented
**
**	char		ftpf_get_size(const char **str)
**	{
**		if (**str == 'l')
**		{
**			(*str)++;
**			if (**str == 'l')
**			{
**				(*str)++;
**				return ('l');
**			}
**			return ('l');
**		}
**		else if (**str == 'h')
**		{
**			(*str)++;
**			if (**str == 'h')
**			{
**				(*str)++;
**				return ('c');
**			}
**			return ('h');
**		}
**		return (0);
**	}
**
**	fmt.size = ft_pf_get_size(str);
*/

t_format	ftpf_get_format(const char **str, va_list arg)
{
	t_format fmt;

	fmt.msk_flag = ftpf_get_flags(str);
	fmt.field = ftpf_get_fields(str, arg);
	if (fmt.field < 0)
	{
		fmt.field = -fmt.field;
		fmt.msk_flag |= ftpf_is_flag('-');
	}
	if (!(**str == '.'))
		fmt.preci = -1;
	else
	{
		(*str)++;
		fmt.preci = ftpf_get_fields(str, arg);
		fmt.msk_flag &= ~(ftpf_is_flag('0'));
	}
	return (fmt);
}
