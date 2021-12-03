/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/03 11:25:38 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **s_buff)
{
	char	*line;
	char	*tmp_buff;
	int		i;

	if (!*s_buff || (*s_buff[0]) == '\0')
		return (NULL);
	i = 0;
	while ((*s_buff)[i] != '\n' && (*s_buff)[i] != 0)
		i++;
	if ((*s_buff)[i] == '\n')
		i++;
	line = ft_substr((*s_buff), 0, i);
	tmp_buff = ft_substr((*s_buff), i, ft_strlen(*s_buff));
	free(*s_buff);
	(*s_buff) = tmp_buff;
	return (line);
}

static void	get_reader(int fd, char **s_buff)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_buff;

	if (BUFFER_SIZE > 8000000)
		return ;
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!*s_buff)
			tmp_buff = ft_strdup(buff);
		else
			tmp_buff = ft_strjoin((*s_buff), buff);
		free (*s_buff);
		(*s_buff) = tmp_buff;
		if (ft_strchr((*s_buff), '\n'))
			return ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	**s_buff = NULL;
	char		*line;
	int			i;

	if (fd < 0)
		return (NULL);
	if (s_buff == NULL)
	{
		s_buff = (char **)malloc(sizeof(char *) * 1024);
		if (!s_buff)
			return (NULL);
		i = 0;
		while (i < 1023)
		{
			s_buff[i] = NULL;
			i++;
		}
	}
	if (!s_buff[fd] || !(ft_strchr(s_buff[fd], '\n')))
		get_reader(fd, (&s_buff[fd]));
	line = get_line(&s_buff[fd]);
	return (line);
}

