/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:53:06 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:08:45 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			str_prec_len(t_param *param)
{
	if (!param->form->precval)
		return (0);
	if (param->form->precval && param->form->precval <
	(int)ft_strlen(param->var->s) && param->form->precval > 0)
		return (param->form->precval);
	return (ft_strlen(param->var->s));
}

int			nbrlen(long int snbr, long unsigned int unbr, char type, int count)
{
	if ((type != 'd' && type != 'i' &&
	type != 'u' && type != 'x' && type != 'X'))
		return (0);
	if ((type == 'x' && unbr < 16) || (type == 'u' && unbr < 10)
	|| (type == 'd' && snbr < 10) ||
	(type == 'X' && unbr < 16) || (type == 'i' && snbr < 10))
		return (count);
	type == 'd' || type == 'i' ? snbr /= 10 : 0;
	type == 'x' || type == 'X' ? unbr /= 16 : 0;
	type == 'u' ? unbr /= 10 : 0;
	count++;
	return (nbrlen(snbr, unbr, type, count));
}

int			var_len(t_param *param)
{
	int negsnbr;

	if (param->precdoublezero && param->conv != 'p')
		return (0);
	if (param->conv == 'c' || param->conv == '%')
		return (1);
	if (param->conv == 'p')
	{
		if (param->precdoublezero)
			return (2);
		else
			return ((nbrlen(param->var->d,
			(long unsigned int)param->var->p, 'x', 1)) + 2);
	}
	if (param->conv == 's')
	{
		if (param->form->isprec)
			return (str_prec_len(param));
		else
			return (ft_strlen(param->var->s));
	}
	negsnbr = param->var->d < 0 ? 1 : 0;
	return (nbrlen(param->var->d < 0 ?
	param->var->d * -1 :
	param->var->d, param->var->u, param->conv, 1) + negsnbr);
}
