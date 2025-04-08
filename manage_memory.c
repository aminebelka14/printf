/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:26:09 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 16:50:34 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_form			*allocate_form(void)
{
	t_form		*form;

	if (!(form = malloc(sizeof(t_form))))
		return (NULL);
	form->isprec = 0;
	form->precval = 0;
	form->iszero = 0;
	form->zeroval = 0;
	form->isdash = 0;
	form->dashval = 0;
	form->iswidth = 0;
	form->widthval = 0;
	return (form);
}

t_param			*allocate_param(void)
{
	t_param		*param;

	if (!(param = malloc(sizeof(t_param))))
		return (NULL);
	if (!(param->form = allocate_form()))
		return (NULL);
	param->format = NULL;
	param->var = NULL;
	param->conv = 0;
	param->precdoublezero = 0;
	param->dispd = 0;
	param->isspace = 0;
	param->next = NULL;
	return (param);
}

void			free_param(t_param *param)
{
	if (param->format)
		free(param->format);
	if (param->var)
		free(param->var);
	if (param->form)
		free(param->form);
	free(param);
}

int				free_param_list(t_param **list, int rval)
{
	t_param		*current;
	t_param		*next;

	current = *list;
	while (current)
	{
		next = current->next;
		free_param(current);
		current = next;
	}
	return (rval);
}
