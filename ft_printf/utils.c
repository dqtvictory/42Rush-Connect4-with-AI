/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:07:14 by qdam              #+#    #+#             */
/*   Updated: 2021/05/24 14:32:21 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pc(char c, int *cnt)
{
	ft_putchar_fd(c, FD);
	(*cnt)++;
}

void	ps(char *s, size_t len, int *cnt)
{
	size_t	i;

	i = 0;
	while (i < len)
		pc(s[i++], cnt);
}

void	pc_repeat(char c, size_t len, int *cnt)
{
	size_t	i;

	i = 0;
	while (i++ < len)
		pc(c, cnt);
}
