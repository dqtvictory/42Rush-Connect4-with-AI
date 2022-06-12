/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 02:22:52 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 11:36:36 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_opts(t_opts *op, const char *fmt)
{
	op->fmt = (char *)fmt;
	op->len = 0;
	op->cnt = 0;
	op->mns = false;
	op->zr = false;
	op->neg_wdth = false;
	op->wdth = 0;
	op->dot = false;
	op->pr = -1;
	op->mod = 0;
	op->spec = 0;
}

static void	print_fmt(va_list vl, t_opts *op)
{
	if (op->spec == 'c')
		return (print_c(vl, op));
	if (op->spec == '%')
		return (print_percent(op));
	if (op->spec == 's')
		return (print_s(vl, op));
	if (op->spec == 'p')
		return (print_p(vl, op));
	if (ft_strhas(op->spec, "di"))
		return (print_d(vl, op));
	if (op->spec == 'u')
		return (print_u(vl, op));
	if (ft_strhas(op->spec, "xX"))
		return (print_x(vl, op));
	if (op->spec == 'n')
		return (print_n(vl, op));
	return (print_invalid(op));
}

static int	format(const char *str, va_list vl, t_opts *op)
{
	char	*s;

	init_opts(op, str);
	s = (char *)str + 1;
	s += check_flag(s, op);
	s += check_num(s, vl, &(op->wdth));
	if (op->wdth < 0)
	{
		op->mns = true;
		op->wdth *= -1;
		op->neg_wdth = true;
	}
	s += check_dot(s, op);
	if (op->dot)
	{
		op->pr = 0;
		s += check_num(s, vl, &(op->pr));
		if (op->pr < 0)
			op->dot = false;
	}
	s += check_modif(s, op);
	s += check_spec(s, op);
	op->len = s - str;
	print_fmt(vl, op);
	return (op->len);
}

int	ft_printf(const char *str, ...)
{
	t_opts	op;
	va_list	vl;

	va_start(vl, str);
	op.total = 0;
	while (*str)
	{
		if (*str != '%')
			pc(*(str++), &op.total);
		else
		{
			str += format(str, vl, &op);
			op.total += op.cnt;
		}
	}
	va_end(vl);
	return (op.total);
}
