/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:23:20 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 16:56:39 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		display_dispatcher(t_param *param)
{
	if (param->precdoublezero && param->conv != 'p')
		return ;
	if (param->conv == '%')
		write(1, "%", 1);
	if (param->conv == 'd' || param->conv == 'i')
		display_d(param);
	if (param->conv == 'c')
		display_c(param);
	if (param->conv == 's')
		display_s(param);
	if (param->conv == 'p')
		display_p(param);
	if (param->conv == 'X')
		display_bigx(param);
	if (param->conv == 'x')
		display_x(param);
	if (param->conv == 'u')
		display_u(param);
}

int			pre_format_dispatcher(t_param *param)
{
	int pre_form_dispd;

	pre_form_dispd = 0;
	if (param->isspace)
		write(1, " ", 1);
	if (param->form->iszero)
		pre_form_dispd += display_0(param);
	if (param->form->iswidth && param->form->widthval > 0)
		pre_form_dispd += display_width(param, 1);
	if (param->form->isprec)
		pre_form_dispd += display_precision(param);
	return (pre_form_dispd + param->isspace);
}

int			post_format_dispatcher(t_param *param)
{
	int post_form_dispd;

	post_form_dispd = 0;
	if (param->form->isdash ||
	(param->form->iszero && param->form->zeroval < 0))
	{
		if (!param->form->isdash)
			param->form->dashval = -param->form->zeroval;
		post_form_dispd += display_dash(param);
	}
	if ((param->form->iswidth && param->form->widthval < 0))
		post_form_dispd += display_width(param, 0);
	return (post_form_dispd);
}

int			display_params(t_param *param, const char *str)
{
	int		i;
	int		displen;

	i = 0;
	displen = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			param->dispd = var_len(param);
			param->dispd += pre_format_dispatcher(param);
			display_dispatcher(param);
			param->dispd += post_format_dispatcher(param);
			displen += param->dispd;
			i += ft_strlen(param->format) + 1;
			param = param->next;
		}
		else
			write(1, &str[i++], 1);
		if (i > (int)ft_strlen(str) || !str[i])
			break ;
	}
	return (displen);
}
