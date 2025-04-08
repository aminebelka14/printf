/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:03:34 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:13:10 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		display_0_with_precision(t_param *param, int diff, int neg)
{
	int i;

	i = 0;
	if (param->conv == '%' || !param->form->isprec || param->conv == 's')
		while (diff > i++)
			write(1, "0", 1);
	else
	{
		while (diff > i++)
			write(1, " ", 1);
		if (neg)
			write(1, "-", 1);
	}
}

int			display_0(t_param *param)
{
	int diff;
	int neg;

	diff = 0;
	neg = 0;
	if ((param->conv == 'd' || param->conv == 'i') && param->var->d < 0)
	{
		if (!param->form->isprec)
			write(1, "-", 1);
		param->var->d *= -1;
		++neg;
	}
	diff += param->form->zeroval -
	((param->form->precval > var_len(param) ?
	param->form->precval : var_len(param)) + neg);
	diff = param->conv == '%' ? param->form->zeroval - 1 : diff;
	display_0_with_precision(param, diff, neg);
	return (diff > 0 ? diff : 0);
}

int			display_precision(t_param *param)
{
	int diff;
	int neg;
	int i;

	diff = 0;
	i = 0;
	neg = 0;
	if (param->conv == 's' || param->conv == '%' ||
	(!param->form->precval && !param->var->d &&
	(param->conv == 'd' || param->conv == 'i')))
		return (0);
	if ((param->conv == 'd' || param->conv == 'i') && param->var->d < 0)
	{
		write(1, "-", 1);
		param->var->d *= -1;
		neg = 1;
	}
	diff += param->form->precval - var_len(param);
	while (diff > i++)
		write(1, "0", 1);
	return (diff > 0 ? diff : 0);
}

int			display_width(t_param *param, int pre)
{
	int diff;
	int neg;
	int i;

	i = 0;
	neg = 0;
	if ((param->conv == 'd' || param->conv == 'i') && param->var->d < 0)
	{
		neg = 1;
		param->var->d *= -1;
	}
	param->form->widthval = param->form->widthval < 0 ?
	param->form->widthval * -1 : param->form->widthval;
	if (param->conv == 's')
		diff = param->form->widthval - (param->form->precval > var_len(param)
		|| !param->form->isprec ? var_len(param) : param->form->precval);
	else if (!pre)
		diff = param->form->widthval - param->dispd;
	else
		diff = param->form->widthval - ((param->form->precval > var_len(param) ?
		param->form->precval : var_len(param)) + neg);
	while (diff > i++)
		write(1, " ", 1);
	neg && pre ? write(1, "-", 1) : 0;
	return (diff > 0 ? diff : 0);
}

int			display_dash(t_param *param)
{
	int diff;
	int i;

	i = 0;
	diff = 0;
	if (param->form->dashval)
		diff += param->form->dashval - param->dispd;
	while (diff > i++)
		write(1, " ", 1);
	return (diff > 0 ? diff : 0);
}
