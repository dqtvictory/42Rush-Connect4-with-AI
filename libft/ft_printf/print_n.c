/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:44:12 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 16:23:13 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_n(va_list vl, t_opts *op)
{
	void	*n;

	n = va_arg(vl, void *);
	if (op->mod == 'l')
		*((long *)n) = op->total;
	else if (op->mod == 'L')
		*((long long *)n) = op->total;
	else if (op->mod == 'h')
		*((short *)n) = op->total;
	else if (op->mod == 'H')
		*((char *)n) = op->total;
	else
		*((int *)n) = op->total;
}
