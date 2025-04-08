/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:24:46 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:13:46 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		prec_flag_parsing(char const *str, int i)
{
	i += is_number(str, i);
	if (is_in_set(str[i], "duixXps%"))
		return (i);
	return (0);
}

int		width_flag_parsing(char const *str, int i)
{
	if (is_in_set(str[i], "duixXscp%"))
		return (i);
	if (str[i] == '.')
	{
		if (str[i + 1] == 'p')
			return (i + 1);
		i += is_number(str, i + 1) + 1;
		if (is_in_set(str[i], "duixXps%"))
			return (i);
	}
	return (0);
}

int		dash_flag_parsing(char const *str, int i)
{
	i += zero_dash_repetition(str, i);
	if (is_in_set(str[i], "duixXscp%"))
		return (i);
	i += is_number(str, i);
	if (str[i] == '.')
	{
		if (str[i + 1] == 'p')
			return (i + 1);
		i += is_number(str, i + 1) + 1;
		if (is_in_set(str[i], "duixXs%"))
			return (i);
	}
	else
		return (i);
	return (0);
}

int		zero_flag_parsing(char const *str, int i)
{
	i += zero_dash_repetition(str, i);
	if (is_in_set(str[i], "duixXs%"))
		return (i);
	i += is_number(str, i);
	if (str[i] == '-')
	{
		i += is_number(str, i + 1) + 1;
		if (str[i] == '.')
		{
			i += is_number(str, i + 1) + 1;
			if (is_in_set(str[i], "duixX%"))
				return (i);
		}
		if (is_in_set(str[i], "duixX%"))
			return (i);
	}
	if (str[i] == '.')
	{
		i += is_number(str, i + 1) + 1;
		if (is_in_set(str[i], "duixXs%"))
			return (i);
	}
	if (is_in_set(str[i], "duixXs%"))
		return (i);
	return (0);
}

int		flag_parsing(t_param *current, char const *str, int i)
{
	int save;

	save = i - 1;
	while (str[i] == ' ')
	{
		++i;
		current->isspace = 1;
	}
	if (is_in_set(str[i], "duixXcsp%"))
		return (i - save);
	if (str[i] == '0')
		return (zero_flag_parsing(str, i + 1) - save);
	if (str[i] == '-')
		return (dash_flag_parsing(str, i + 1) - save);
	if (is_number(str, i))
		return (width_flag_parsing(str, i + is_number(str, i)) - save);
	if (str[i] == '.')
		return (prec_flag_parsing(str, i + 1) - save);
	return (0);
}
