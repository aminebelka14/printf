/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:55:42 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/17 18:00:02 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	if (!set[i])
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_number(char const *str, int i)
{
	int count;

	count = 1;
	if (str[i] == '*')
		return (1);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[++i]))
		++count;
	return (count);
}
