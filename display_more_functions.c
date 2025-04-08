/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_more_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:57:27 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/17 16:58:17 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void			display_u(t_param *param)
{
	if (param->precdoublezero)
		return ;
	ft_putunbr_fd(param->var->u, 1);
}

void			display_p(t_param *param)
{
	write(1, "0x", 2);
	if (!param->var->p && param->precdoublezero)
		return ;
	ft_putnbr_base((long int)param->var->p, "0123456789abcdef");
}
