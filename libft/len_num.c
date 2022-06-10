/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:13:38 by qdam              #+#    #+#             */
/*   Updated: 2021/05/13 20:45:25 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_s(ssize_t num, size_t base)
{
	size_t	n;
	size_t	d;

	if (!num)
		return (1);
	n = (-num * (num < 0)) + (num * (num > 0));
	d = (num < 0);
	while (n)
	{
		n /= base;
		d++;
	}
	return (d);
}

size_t	ft_len_u(size_t num, size_t base)
{
	size_t	d;

	if (!num)
		return (1);
	d = 0;
	while (num)
	{
		num /= base;
		d++;
	}
	return (d);
}
