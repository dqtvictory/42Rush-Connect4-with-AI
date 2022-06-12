/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:05:02 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 11:38:12 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(const char *str, t_opts *op)
{
	char	*s;

	s = (char *)str;
	while (ft_strhas(*s, FLAGS))
	{
		op->mns = (op->mns || *s == '-');
		op->zr = (op->zr || *s == '0');
		s++;
	}
	if (op->mns && op->zr)
		op->zr = false;
	return (s - str);
}

int	check_num(const char *str, va_list vl, int *numptr)
{
	int	i;

	i = 0;
	if (ft_isdigit(*str))
	{
		*numptr = ft_atoi(str);
		while (ft_isdigit(str[i]))
			i++;
		return (i);
	}
	else if (*str == '*')
	{
		*numptr = va_arg(vl, int);
		return (1);
	}
	return (0);
}

int	check_dot(const char *str, t_opts *op)
{
	op->dot = (*str == '.');
	return (op->dot);
}

int	check_modif(const char *str, t_opts *op)
{
	char	*s;
	int		h;
	int		l;

	s = (char *)str;
	h = 0;
	l = 0;
	while (ft_strhas(*s, MODIFS))
	{
		if (*s == 'h')
			h++;
		else if (*s == 'l')
			l++;
		s++;
	}
	if (l == 2)
		op->mod = 'L';
	else if (l > 0)
		op->mod = 'l';
	else if (h == 2)
		op->mod = 'H';
	else if (h > 0)
		op->mod = 'h';
	return (s - str);
}

int	check_spec(const char *str, t_opts *op)
{
	if (ft_strhas(*str, SPECS))
	{
		op->spec = *str;
		return (1);
	}
	return (0);
}
