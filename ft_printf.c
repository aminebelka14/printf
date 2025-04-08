/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:18:29 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:12:28 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int				manage_args(const char *str, va_list ap)
{
	t_param		*params;
	int			len;
	int			varlen;

	if ((len = (check_string(&params, str, ap))) < 0)
		return (-1);
	varlen = display_params(params, str);
	len += varlen;
	if (len >= 0)
		free_param_list(&params, 0);
	va_end(ap);
	return (len);
}

int				ft_printf(const char *str, ...)
{
	va_list(ap);

	va_start(ap, str);
	return (manage_args(str, ap));
}
