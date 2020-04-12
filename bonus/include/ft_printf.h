#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

#define BASE10		"0123456789"
#define BASE16_LOW	"0123456789abcdef"
#define BASE16_UPP	"0123456789ABCDEF"
#define FLAGS		"0- +#'"
#define FLAG_MIN	2
#define FLAG_0		1
#define TYPES		"cspdiuxX%"

typedef struct	s_format
{
	char	msk_flag;
	int	field;
	int	preci;
	char	size;
	char	type;
}		t_format;

/*
**	ft_ruler : to mesure nbrlen
*/

int		ftpf_ruler_i(int nbr, t_format fmt);
int		ftpf_ruler_u(unsigned int nbr, t_format fmt);
int		ftpf_ruler_x(unsigned int nbr, t_format fmt);
int		ftpf_ruler_p(unsigned long nbr, t_format fmt);
int		ftpf_ruler_s(char *str, t_format fmt);

/*
**	ft_putnbr_signed : functions printing signed value
*/

int		ftpf_putf_i(int nbr, t_format fmt);
int		ftpf_putf_u(unsigned int nbr, t_format fmt);
int		ftpf_putf_p(unsigned int nbr, t_format fmt);
int		ftpf_putf_s(char *str, t_format fmt);
int		ftpf_putf_c(unsigned char nbr, t_format fmt);


int		ftpf_i(int nbr, t_format fmt);
int		ftpf_u(unsigned int nbr, t_format fmt);
int		ftpf_p(unsigned int nbr, t_format fmt);
int		ftpf_s(char *str, t_format fmt);
int		ftpf_c(unsigned char nbr, t_format fmt);

/*
**	ft_caller : to call the gud function
*/

int		ft_call_u(t_format fmt);
int		ft_call_i(t_format fmt);

/*
**	ft_prefix : to add prefix
*/

int		ft_prefix(t_format fmt);
int		ft_padding(t_format fmt);
int		ft_padding_0(t_format fmt);


/*
**
*/

char		ftpf_get_flags(const char **str);
int		ftpf_get_fields(const char **str, va_list arg);
char		ftpf_get_size(const char **str);
t_format	ftpf_get_format(const char **str, va_list arg);

/*
**
*/

int		ft_post_format(const char **str, va_list arg);
int		ft_post_str(const char **str);
int		ft_printf(const char *str, ...);

/*
**	ft_utils : nice to have
*/

char		ftpf_is_flag(char c);
char		ftpf_is_mask(char *str);
#endif
