/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:31:51 by mharriso          #+#    #+#             */
/*   Updated: 2020/11/22 19:25:49 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int cut_next_line(char *buffer, char *new_line, char *cache)
{
	return 0;
}

int	save_next_line(char *buffer, char **line)
{
	char	*new_line;
	char	*update_line;

	if((new_line = ft_strchr(buffer, '\n')))
		*new_line = '\0';
	if(!(update_line = ft_strjoin(*line, buffer)))
		return (-1);
	free(*line);
	*line = update_line;
	//if(new_line)
		//cut_next_line(buffer, new_line, cache);
	return (new_line) ? 1 : 0;
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	char		buffer[BUFFER_SIZE + 1];
	int			res;

	if(!(*line = ft_strdup("")))
		return (-1);


	while((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		res = save_next_line(buffer, line, cache);
		if(res != 0)
			break ;
	}
	if(res == -1)
	{
		free(cache);
		free(*line);
	}
	return (res);
}
