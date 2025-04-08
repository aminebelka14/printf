/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:28:00 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/04 15:42:35 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char		*ft_strdup_free(char *src, int ifree)
{
	char		*dest;
	size_t		i;

	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	if (ifree)
		free(src);
	return (dest);
}

char		*ft_substr_free(char *s, unsigned int start, size_t len, int ifree)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) == 1 && s[0] == '\n') || !len || ft_strlen(s) < start)
	{
		if (ifree)
			free(s);
		return (ft_strdup_free("\0", 0));
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i])
		str[i++] = s[start++];
	str[i] = '\0';
	if (ifree)
		free(s);
	return (str);
}

char		*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dest)
		return (src);
	if (!src || !nb)
		return (dest);
	while (dest[i])
		++i;
	while (src[j] && nb)
	{
		dest[i] = src[j];
		i++;
		j++;
		--nb;
	}
	dest[i] = '\0';
	return (dest);
}

char		*cncat(char *str1, char *str2, int ifree1, int ifree2)
{
	char		*str3;
	size_t		i;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_strdup_free(str2, ifree2));
	if (!str2)
		return (ft_strdup_free(str1, ifree1));
	if (!(str3 = malloc(sizeof(char) *
	(ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	i = -1;
	while (++i < (size_t)(ft_strlen(str1) + ft_strlen(str2) + 1))
		str3[i] = '\0';
	str3 = ft_strncat(ft_strncat(str3, str1,
	ft_strlen(str1)), str2, ft_strlen(str2));
	ifree1 ? free(str1) : 0;
	if (ifree2)
		free(str2);
	return (str3);
}
