/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:02:46 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 16:49:31 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char				*strmalloc(char *src)
{
	char		*str;
	int			i;
	int			size;

	if (!src)
		return (NULL);
	i = -1;
	size = ft_strlen(src);
	if (!(str = malloc(sizeof(char) * size)))
		return (NULL);
	while (++i < size)
		str[i] = src[i];
	return (src);
}

int					extract_arg_from_list(t_param *current, va_list ap)
{
	if (!(current->var = malloc(sizeof(t_var))))
		return (-1);
	current->var->d = (current->conv == 'd' || current->conv == 'i' ?
	va_arg(ap, int) : 0);
	current->var->c = (current->conv == 'c' ? va_arg(ap, int) : 0);
	current->var->u = ((current->conv == 'u' || current->conv == 'x' ||
	current->conv == 'X') ? va_arg(ap, unsigned int) : 0);
	current->var->s = (current->conv == 's' ? va_arg(ap, char *) : NULL);
	if (current->conv == 's' && !current->var->s &&
	!(current->form->isprec && !current->form->precval))
		if (!(current->var->s = strmalloc("(null)")))
			return (-1);
	current->var->p = (current->conv == 'p' ? va_arg(ap, void *) : NULL);
	return (0);
}

void				is_precision_double_zero(t_param *param)
{
	if (param->form->isprec && !param->form->precval &&
	((param->conv == 'p' && !param->var->p) ||
	((param->conv == 'd' || param->conv == 'i') && !param->var->d) ||
	((param->conv == 'u' || param->conv == 'x' || param->conv == 'X')
	&& !param->var->u)))
		param->precdoublezero = 1;
}

int					parse_string(t_param *current, char const *str,
va_list ap, t_pars_str *prstr)
{
	int flen;

	if ((flen = flag_parsing(current, str, prstr->i + 1)) <= 0)
		return (-1);
	if (!(current->format = ft_substr_free((char *)str, prstr->i + 1, flen, 0)))
		return (-1);
	current->conv = str[prstr->i + flen];
	form_parsing(current->form, current->format, ap);
	if (extract_arg_from_list(current, ap) < 0)
		return (-1);
	is_precision_double_zero(current);
	prstr->efflen += flen + 1;
	prstr->i += flen;
	return (0);
}

int					check_string(t_param **sent, char const *str, va_list ap)
{
	t_pars_str	*prstr;
	t_param		*current;
	t_param		*next;

	if (!(current = allocate_param()))
		return (-1);
	*sent = current;
	if (!(prstr = allocate_pars_str(current)))
		return (free_param_list(sent, -1));
	while (str[prstr->i])
	{
		if (str[prstr->i] == '%')
		{
			if (current->var)
				if (!(next = allocate_next_elem(&current)))
					return (free_param_list(sent, -1));
			if (parse_string(current, str, ap, prstr) < 0)
				return (free_param_list(sent, -1));
		}
		++prstr->i;
	}
	free(prstr);
	return (ft_strlen(str) - prstr->efflen);
}
