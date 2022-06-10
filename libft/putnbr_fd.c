/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdam <qdam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 01:32:01 by qdam              #+#    #+#             */
/*   Updated: 2021/04/16 01:32:01 by qdam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putfd_s_base(int fd, ssize_t num, char *base)
{
	size_t	n;
	size_t	len;

	if (!num)
	{
		write(fd, base, 1);
		return ;
	}
	if (num < 0)
		n = -num;
	else
		n = num;
	len = ft_strlen(base);
	if (n >= len)
		ft_putfd_s_base(fd, n / len, base);
	write(fd, base + (n % len), 1);
}

void	ft_putfd_u_base(int fd, size_t num, char *base)
{
	size_t	len;

	if (!num)
	{
		write(fd, base, 1);
		return ;
	}
	len = ft_strlen(base);
	if (num >= len)
		ft_putfd_u_base(fd, num / len, base);
	write(fd, base + (num % len), 1);
}
