/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:33:39 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 16:46:41 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_print_d(t_opts *op, ssize_t n)
{
	size_t	digits;
	size_t	len_n;

	digits = ft_len_u(-n * (n < 0) + n * (n > 0), 10);
	len_n = digits + (n < 0);
	if (op->pr >= 0)
		len_n += (op->pr - (int)digits) * (op->pr > (int)digits);
	else if (op->zr && !op->mns && op->wdth > (int)len_n)
		len_n = op->wdth;
	if (op->wdth >= (int)len_n && !op->mns)
		pc_repeat(' ', op->wdth - (int)len_n + (!n && !op->pr), &op->cnt);
	if (n < 0)
		pc('-', &op->cnt);
	if (len_n > digits + (n < 0))
		pc_repeat('0', len_n - digits - (n < 0), &op->cnt);
	if (n || op->pr)
	{
		ft_putfd_u_base(FD, -n * (n < 0) + n * (n > 0), BASE10);
		op->cnt += digits;
	}
	if (op->wdth > (int)len_n && op->mns)
		pc_repeat(' ', op->wdth - (int)len_n + (!n && !op->pr), &op->cnt);
}

void	print_d(va_list vl, t_opts *op)
{
	ssize_t	n;

	if (op->mod == 'l')
		n = va_arg(vl, long);
	else if (op->mod == 'L')
		n = va_arg(vl, long long);
	else if (op->mod == 'h')
		n = (short)va_arg(vl, int);
	else if (op->mod == 'H')
		n = (char)va_arg(vl, int);
	else
		n = va_arg(vl, int);
	do_print_d(op, n);
}
