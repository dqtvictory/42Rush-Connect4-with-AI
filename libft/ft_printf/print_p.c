/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:32:55 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 14:44:56 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(va_list vl, t_opts *op)
{
	size_t	n;
	size_t	digits;
	size_t	len_n;

	n = va_arg(vl, size_t);
	digits = ft_len_u(n, 16);
	len_n = digits;
	if (op->pr >= 0)
		len_n += (op->pr - (int)digits) * (op->pr > (int)digits);
	else if (op->zr && op->wdth > (int)len_n)
		len_n = op->wdth;
	if (op->wdth > (int)len_n + 2 && !op->mns)
		pc_repeat(' ', op->wdth - (int)len_n - 2 + (!n && !op->pr), &op->cnt);
	ps("0x", 2, &op->cnt);
	if (len_n > digits)
		pc_repeat('0', len_n - digits, &op->cnt);
	if (n || op->pr)
	{
		ft_putfd_u_base(FD, n, BASE16LC);
		op->cnt += digits;
	}
	if (op->wdth > (int)len_n + 2 && op->mns)
		pc_repeat(' ', op->wdth - (int)len_n - 2 + (!n && !op->pr), &op->cnt);
}
