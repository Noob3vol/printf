#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
#include "libft.h"
#define FLAGS "-0"
#define	FIELD ".*0123456789"
#define	FORMAT "cspdiuxX%"

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
** Token Processor
*/
void	ft_handle_flags(char **str, t_db *param);
void	ft_handle_fields(char **str, t_db *param, va_list *fields);
int	ft_handle_formats(char c, t_db param, va_list *arg);

/*
** Error function
*/

int	ft_dump_tokens(t_db *param);

#endif
