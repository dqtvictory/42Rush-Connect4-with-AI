/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:53:32 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 14:32:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(va_list vl, t_opts *op)
{
	char	*s;
	size_t	len;

	s = va_arg(vl, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (op->pr >= 0 && (size_t)(op->pr) < len)
		len = op->pr;
	if ((size_t)op->wdth <= len)
		return (ps(s, len, &op->cnt));
	if (op->mns)
		ps(s, len, &op->cnt);
	pc_repeat(' ', (size_t)op->wdth - len, &op->cnt);
	if (!op->mns)
		ps(s, len, &op->cnt);
}
