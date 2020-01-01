#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"
#define FLAGS "-0"
#define	FIELD ".*0123456789"
#define	FORMAT "cspdiuxX%"


/*
 *	Analyser
*/
int	ft_is_field(char c)
{
	if ((c >= '1' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int	ft_is_flags(char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int	ft_is_format(char c)
{
	char 	formats[] = FORMATS;
	int	i;

	i = 0;
	while (flags[i])
	{	if (c == flags[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
/*
** Handler
*/

int	ft_handle_field(char **str, t_db *param)
{
	char b_dot;

	while (**str)
	{
		if (((**str == '.' || param->precision >= 0) && b_dot) 
				|| **str == '*' && !b_dot && param->width >= 0)
			return (-1);
		if (((**str >= '0' && **str <= '9')))
			param->width = pf_atoi(str);
	if (b_dot = (**str == '.'))
	{
		param->precision = 0;
		(*str)++;
	}
	{
		if (param->width >= 0)
			
		if (param->precision >= 0 &&	
	else	if(**str == '*')
	else
				return (1);
	}
	return (0);
}

/*
 * Format processor
*/


int	pf_per(t_db, void *)
{
	write(1, "%", 1);
	return (1);
}

int	(*ptr)(t_db, void *)ft_handle_format(t_db param, char c)
{
	int	(*fntab[])(t_db, void *) = 
	{
		&pf_c,
		&pf_s, 
		&pf_p, 
		&pf_d, 
		&pf_i, 
		&pf_u, 
		&pf_x, 
		&pf_X,
		&pf_per
	}
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (!c)
		return (-1);
}

void	ft_init_param(t_db *param, char **str, int *i)
{
	param->flags_mask = 0;
	width = -1;
	precision =-1;
	*str = &((*str)[i]);
	i = 0;
}



int	ft_pf_atoi(char **str)
{
	int	nbr;

	nbr = 0;
	while (**str >= '0' && **str <= '9')
	{
		str 


int	ft_handle_flags(char c, t_db *param)
{
		if (!c)
			return (-1);
		if (c == '-')
			param->flags_mask &= 1;
		if (c == '0')
			param->flags_mask &= 2;
	return (1);
}



int	ft_printf(char *str, ...)
{
	int 	i;
	int	count;
	t_db	param;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += write(1, str, i);
			ft_init_param(&param, &str, &i);
			if (!ft_handle_flags(&str, &param))
			return (-1);
		}
		i++;
	}
	count += write(1, str, i);
	return (count);
}

int	main(void)
{
		ft_printf("Hello World");
		return (0);
}
