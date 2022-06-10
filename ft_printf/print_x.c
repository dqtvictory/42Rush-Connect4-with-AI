/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:27:40 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 16:48:14 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_print_x(t_opts *op, ssize_t n)
{
	size_t	digits;
	size_t	len_n;

	digits = ft_len_u(n, 16);
	len_n = digits;
	if (op->pr >= 0)
		len_n += (op->pr - (int)digits) * (op->pr > (int)digits);
	else if (op->zr && !op->mns && op->wdth > (int)len_n)
		len_n = op->wdth;
	if (op->wdth >= (int)len_n && !op->mns)
		pc_repeat(' ', op->wdth - (int)len_n + (!n && !op->pr), &op->cnt);
	if (len_n > digits)
		pc_repeat('0', len_n - digits, &op->cnt);
	if (n || op->pr)
	{
		if (op->spec == 'x')
			ft_putfd_u_base(FD, n, BASE16LC);
		else
			ft_putfd_u_base(FD, n, BASE16UC);
		op->cnt += digits;
	}
	if (op->wdth > (int)len_n && op->mns)
		pc_repeat(' ', op->wdth - (int)len_n + (!n && !op->pr), &op->cnt);
}

void	print_x(va_list vl, t_opts *op)
{
	ssize_t	n;

	if (op->mod == 'l')
		n = va_arg(vl, unsigned long);
	else if (op->mod == 'L')
		n = va_arg(vl, unsigned long long);
	else if (op->mod == 'h')
		n = (unsigned short)va_arg(vl, unsigned int);
	else if (op->mod == 'H')
		n = (unsigned char)va_arg(vl, unsigned int);
	else
		n = va_arg(vl, unsigned int);
	do_print_x(op, n);
}
