/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:10:53 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/17 17:04:54 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int		is_neg(const char *str, int *i)
{
	int minus;

	minus = 0;
	if (str[*i] == '-')
	{
		++minus;
		++(*i);
	}
	else if (str[*i] == '+')
	{
		++(*i);
	}
	return (minus);
}

static int		pwr(int nb, int exp)
{
	int save;

	save = nb;
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (nb);
	while (exp - 1)
	{
		nb = nb * save;
		--exp;
	}
	return (nb);
}

int				ft_atoi(const char *str)
{
	int i;
	int neg;
	int nb;
	int j;

	nb = 0;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13)
	|| str[i] == ' ' || str[i] == '.'))
		++i;
	neg = is_neg(str, &i);
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	while (i > j)
	{
		nb += (str[j] - '0') * pwr(10, i - j - 1);
		++j;
	}
	return (nb);
}
