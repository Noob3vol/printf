/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:10:25 by iguidado          #+#    #+#             */
/*   Updated: 2020/02/12 18:35:04 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../lib/include/libft.h"
# include <stdarg.h>
# include <unistd.h>
# define FLAGS "-0"
# define FIELD ".*0123456789"
# define FORMAT "cdiuxX"

typedef	struct	s_db
{
	char	flags_mask;
	int		width;
	int		precision;
	int		count;
	int		star_count;
}				t_db;

int				ft_printf(char *str, ...);

/*
** Charactere processing
*/
int				ft_is_flag(char c);
int				ft_is_field(char c);
int				ft_is_format(char c, char *formats);

/*
** Utils
*/
int				ft_abs(int nbr);
int				ft_pf_atoi(char **str);
int				ft_nbrlen(int nbr);
int				ft_nbrlen_u(unsigned int nbr);
int				ft_nbrlen_x(unsigned int nbr);
int				ft_nbrlen_p(unsigned long nbr);
int				ft_nbrlen_base(int nbr, int base);

/*
** Error function
*/
int				ft_dump_tokens(t_db tokens);

/*
** Token Processor
*/
void			ft_handle_flags(char **str, t_db *param);
void			ft_handle_field(char **str, t_db *param, va_list *fields);
int				ft_handle_format(char c, t_db param, va_list *arg);

/*
** Print Format
*/
int				pf_c(t_db tokens, int	value);
int				pf_s(t_db tokens, char *str);
int				pf_p(t_db tokens, char *value);
int				pf_d(t_db tokens, int	value);
int				pf_i(t_db tokens, int nbr);
int				pf_u(t_db tokens, int	value);
int				pf_x(t_db tokens, int	value);
int				pf_hex(t_db tokens, int	value);
int				pf_f(t_db tokens, double	value);

/*
** Print Symbol
*/
void			ft_pf_putnbr(int nbr, int *count);
void			ft_putnbr_len(int nbr, int len, int *count);
void			ft_putnbr_len_u(unsigned int nbr, int len, int *count);
void			ft_putnbr_len_x(unsigned int nbr, int len, int *count);
void			ft_putnbr_len_hex(unsigned int nbr, int len, int *count);
void			ft_putnbr_len_p(unsigned long nbr, int len, int *count);
void			ft_putnbr_len_f(double nbr, int len, int *count);

int				pf_left_paggin(t_db *tokens, int print_len);
int				pf_left_paggin_i(t_db *tokens, int print_len);
int				pf_left_paggin_s(t_db *tokens, int print_len);
int				pf_left_paggin_1(t_db *tokens, int print_len);
#endif
