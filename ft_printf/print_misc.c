/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:09:17 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 11:53:45 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_opts *op)
{
	int		i;

	if (op->wdth <= 1)
		return (pc('%', &op->cnt));
	if (op->mns)
		pc('%', &op->cnt);
	i = 1;
	while (i++ < op->wdth)
	{
		if (op->zr && !op->mns)
			pc('0', &op->cnt);
		else
			pc(' ', &op->cnt);
	}
	if (!op->mns)
		pc('%', &op->cnt);
}

void	print_invalid(t_opts *op)
{
	if (op->mns || op->neg_wdth)
		pc('-', &op->cnt);
	if ((!op->mns || op->neg_wdth) && op->zr)
		pc('0', &op->cnt);
	if (op->wdth)
	{
		ft_putfd_u_base(FD, op->wdth, BASE10);
		op->cnt += ft_len_u(op->wdth, 10);
	}
	if (op->dot)
	{
		pc('.', &op->cnt);
		ft_putfd_u_base(FD, op->pr, BASE10);
		op->cnt += ft_len_u(op->pr, 10);
	}
}
