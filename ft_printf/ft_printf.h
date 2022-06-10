/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 02:25:12 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 16:59:25 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

# define FD 1

# define DIGITS "1234567890"
# define FLAGS "-0"
# define MODIFS "hl"
# define SPECS "cspdiuxX%n"
# define MISCS ".*"

# define BASE10 "0123456789"
# define BASE16UC "0123456789ABCDEF"
# define BASE16LC "0123456789abcdef"

struct	s_opts
{
	int		total;
	char	*fmt;
	size_t	len;
	int		cnt;
	bool	mns;
	bool	zr;
	bool	neg_wdth;
	int		wdth;
	bool	dot;
	int		pr;
	char	mod;
	char	spec;
};
typedef struct s_opts	t_opts;

void	pc(char c, int *cnt);
void	ps(char *s, size_t len, int *cnt);
void	pc_repeat(char c, size_t len, int *cnt);
char	*str_concat(size_t n, ...);

int		check_flag(const char *str, t_opts *op);
int		check_num(const char *str, va_list vl, int *numptr);
int		check_dot(const char *str, t_opts *op);
int		check_modif(const char *str, t_opts *op);
int		check_spec(const char *str, t_opts *op);

void	print_c(va_list vl, t_opts *op);
void	print_percent(t_opts *op);
void	print_s(va_list vl, t_opts *op);
void	print_p(va_list vl, t_opts *op);
void	print_d(va_list vl, t_opts *op);
void	print_u(va_list vl, t_opts *op);
void	print_x(va_list vl, t_opts *op);
void	print_n(va_list vl, t_opts *op);
void	print_invalid(t_opts *op);

int		ft_printf(const char *str, ...);

#endif
