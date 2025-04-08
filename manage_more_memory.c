/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_more_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:46:52 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/17 18:00:16 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_pars_str			*allocate_pars_str(t_param *first)
{
	t_pars_str	*prstr;

	if (!(prstr = malloc(sizeof(t_pars_str))))
		return (NULL);
	prstr->i = 0;
	prstr->efflen = 0;
	prstr->first = first;
	return (prstr);
}

t_param				*allocate_next_elem(t_param **current)
{
	t_param *next;

	if (!(next = allocate_param()))
		return (NULL);
	(*current)->next = next;
	(*current) = next;
	return (next);
}
