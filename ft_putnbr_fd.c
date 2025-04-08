/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:31 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/18 16:59:34 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void		putdigit(int n, int fd)
{
	char c;

	c = n + '0';
	write(fd, &c, 1);
}

void			ft_putnbr_fd(long int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb < 10)
		putdigit(nb % 10, fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

void			ft_putunbr_fd(unsigned int nb, int fd)
{
	if (nb < 10)
		putdigit(nb % 10, fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
