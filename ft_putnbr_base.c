/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:31 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/15 18:52:12 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void		putdigit(int n, char *base)
{
	write(1, &base[n], 1);
}

void			ft_putnbr_base(long int nb, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nb, base);
	}
	else if (nb < 16)
		putdigit(nb % 16, base);
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16, base);
		ft_putnbr_base(nb % 16, base);
	}
}
