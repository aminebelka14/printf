/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 15:44:44 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/18 18:54:49 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void			display_d(t_param *param)
{
	if (!param->var->d && param->precdoublezero)
		return ;
	ft_putnbr_fd(param->var->d, 1);
}

void			display_s(t_param *param)
{
	if (param->form->isprec && param->form->precval >= 0)
	{
		if (!param->form->precval)
			return ;
		if (param->form->precval && param->form->precval
		< (int)ft_strlen(param->var->s))
		{
			write(1, param->var->s, param->form->precval);
			return ;
		}
	}
	write(1, param->var->s, ft_strlen(param->var->s));
}

void			display_x(t_param *param)
{
	if (param->precdoublezero)
		return ;
	ft_putnbr_base(param->var->u, "0123456789abcdef");
}

void			display_c(t_param *param)
{
	write(1, &(param->var->c), 1);
}

void			display_bigx(t_param *param)
{
	if (param->precdoublezero)
		return ;
	ft_putnbr_base(param->var->u, "0123456789ABCDEF");
}
