/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:13:28 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:17:49 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			get_dash_value(va_list ap)
{
	int arg;

	arg = va_arg(ap, int);
	arg = arg > 0 ? arg : arg * -1;
	return (arg);
}

int			zero_dash_repetition(char const *str, int i)
{
	int save;

	save = i;
	while (is_in_set(str[i], "-0"))
		++i;
	return (i - save);
}
