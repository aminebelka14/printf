/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:41:16 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:17:15 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int			zero_parsing(t_form *form, char *str, va_list ap, int i)
{
	int		save;

	save = i;
	form->iszero = 1;
	if (is_number(str, i + 1))
	{
		if (str[i + 1] == '*')
		{
			form->zeroval = va_arg(ap, int);
			i += 2;
		}
		else
		{
			form->zeroval = ft_atoi(&str[i + 1]);
			while (str[i + 1] == '0')
				++i;
			if (is_number(str, i + 1))
				i += nbrlen(form->zeroval, 0, 'd', 1) + 1;
		}
	}
	else
		i += 1;
	return (i - save);
}

int			dash_parsing(t_form *form, char *str, va_list ap, int i)
{
	int		save;

	save = i;
	form->isdash = 1;
	while (str[i + 1] == '-')
		++i;
	if (is_number(str, i + 1))
	{
		if (str[i + 1] == '*')
		{
			form->dashval = get_dash_value(ap);
			i += 2;
		}
		else
		{
			form->dashval = ft_atoi(&str[i + 1]);
			while (str[i + 1] == '0')
				++i;
			if (is_number(str, i + 1))
				i += nbrlen(form->dashval, 0, 'd', 1) + 1;
		}
	}
	else
		i += 1;
	return (i - save);
}

int			width_parsing(t_form *form, char *str, va_list ap, int i)
{
	int		save;

	save = i;
	form->iswidth = 1;
	if (str[i] == '*')
	{
		form->widthval = va_arg(ap, int);
		++i;
	}
	else
	{
		form->widthval = ft_atoi(&str[i]);
		i += nbrlen(form->widthval, 0, 'd', 1);
	}
	return (i - save);
}

int			prec_parsing(t_form *form, char *str, va_list ap, int i)
{
	int		save;

	save = i;
	form->isprec = 1;
	if (is_number(str, i + 1))
	{
		if (str[i + 1] == '*')
		{
			form->precval = va_arg(ap, int);
			form->precval < 0 ? form->isprec = 0 : 0;
			i += 2;
		}
		else
		{
			form->precval = ft_atoi(&str[i + 1]);
			while (str[i + 1] == '0')
				++i;
			if (is_number(str, i + 1))
				i += nbrlen(form->precval, 0, 'd', 1) + 1;
		}
	}
	else
		i += 1;
	return (i - save);
}

int			form_parsing(t_form *form, char *str, va_list ap)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			i += zero_parsing(form, str, ap, i);
		}
		if (is_number(str, i))
		{
			i += width_parsing(form, str, ap, i);
		}
		if (str[i] == '-')
		{
			i += dash_parsing(form, str, ap, i);
		}
		if (str[i] == '.')
		{
			i += prec_parsing(form, str, ap, i);
		}
		++i;
	}
	return (0);
}
