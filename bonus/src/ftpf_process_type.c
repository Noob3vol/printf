#include "ft_printf.h"


int	ft_put_u(unsigned int nbr, t_format fmt)
{
	int count;
	int pref_len;

	

}

int	pf_u(va_list ap, t_format fmt)
{
	int	(*ft_putf[])(void *, t_format);

	if (fmt.size = 'l')
		return (pf_lu(va_arg(arg, unsigned long)));
	if (fmt.size = 'L')
		return (pf_llu(va_arg(arg, unsigned long long)));
	if (fmt.size = 'h')
		return (pf_hu(va_arg(arg, unsigned short)));
	if (fmt.size = 'H')
		return (pf_hhu(va_arg(arg, unsigned char)));
	return (
}

int	pf_c(va_list ap, t_format fmt)
{
}

void	ft_load_ftype_tab(int (*ft_pf[])(
int	ftpf_process_type(const char **str, va_list ap)
{
	t_format fmt;
	int	(*ft_pf[5])(va_list, t_format);

	fmt = ft_pf_get_format(str, ap);
	if (!(fmt.type = **str))
		return (-1);
	if (fmt.type == '%')
		return (write(1, "%", 1));
	if (fmt.type == 'p')
		return (pf_p);
	if (fmt.type == 'u' || fmt.type == 'x' || fmt.type == 'X')
		return (pf_u);
	if (fmt.type == 'i' || fmt.type == 'd')
		return (pf_i);
	if (fmt.type == 'p')
	else if (fmt.type)

}
