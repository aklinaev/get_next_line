/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 03:02:15 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/01 23:31:41 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char			*ft_strchr(const char *str, int c)
{
	while (*str != c && *str)
		str++;
	return ((*str == c) ? (char *)str : NULL);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*s;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (*s1)
			s[i] = *(s1++);
		else
			s[i] = *(s2++);
		i++;
	}
	s[i] = '\0';
	return (s);
}

char			*ft_strdup(const char *str)
{
	size_t	i;
	char	*dup;

	if (!(dup = malloc(ft_strlen(str) + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
