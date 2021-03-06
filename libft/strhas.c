/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:19:21 by qdam              #+#    #+#             */
/*   Updated: 2021/05/13 20:20:15 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strhas(char c, const char *str)
{
	return (ft_stridx(c, str) >= 0);
}
