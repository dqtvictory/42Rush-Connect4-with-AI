/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:15:07 by qdam              #+#    #+#             */
/*   Updated: 2021/04/09 16:15:07 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_uchar	*uc1;
	t_uchar	*uc2;
	size_t	i;

	uc1 = (t_uchar *)s1;
	uc2 = (t_uchar *)s2;
	i = 0;
	while (uc1[i] || uc2[i])
	{
		if (i < n && uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	return (0);
}
