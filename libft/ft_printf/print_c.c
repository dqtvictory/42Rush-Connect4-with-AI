/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:40:31 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 14:31:47 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list vl, t_opts *op)
{
	char	c;
	int		i;

	c = va_arg(vl, int);
	if (op->wdth <= 1)
		return (pc(c, &op->cnt));
	if (op->mns)
		pc(c, &op->cnt);
	i = 1;
	while (i++ < op->wdth)
		pc(' ', &op->cnt);
	if (!op->mns)
		pc(c, &op->cnt);
}
