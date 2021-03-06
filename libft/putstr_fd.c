/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:26:51 by qdam              #+#    #+#             */
/*   Updated: 2021/04/16 01:26:51 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_fd(wchar_t *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putwchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}
