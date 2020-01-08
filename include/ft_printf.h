#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
//#include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# define FLAGS "-0"
# define FIELD ".*0123456789"
# define FORMAT "cspdiuxX%"
#define TEST write(1, "TEST\n", 5)

typedef	struct	s_db
{
	char	flags_mask;
	int	width;
	int	precision;
}		t_db;

/*
** Charactere processing
*/
int	ft_is_flag(char c);
int	ft_is_field(char c);
int	ft_is_format(char c);

/*
** Utils
*/
int	ft_abs(int nbr);
int	ft_pf_atoi(char **str);
void	ft_pf_putnbr(int nbr, int *count);

/*
** Error function
*/

int	ft_dump_tokens(t_db tokens);

/*
** Token Processor
*/

void	ft_handle_flags(char **str, t_db *param);
void	ft_handle_field(char **str, t_db *param, va_list *fields);
int	ft_handle_format(char c, t_db param, va_list *arg);

/*
** Print Format
*/

int	pf_c(t_db tokens, void *value);
int	pf_s(t_db tokens, void *value);
int	pf_p(t_db tokens, void *value);
int	pf_d(t_db tokens, void *value);
int	pf_i(t_db tokens, void *value);
int	pf_u(t_db tokens, void *value);
int	pf_x(t_db tokens, void *value);
int	pf_X(t_db tokens, void *value);
#endif
