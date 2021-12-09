/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/09 12:05:49 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **s_buff)
{
	char	*line;
	char	*tmp_buff;
	int		i;

	if (!*s_buff || (*s_buff)[0] == '\0')
	{
		free (*s_buff);
		*s_buff = NULL;
		return (NULL);
	}
	i = 0;
	while ((*s_buff)[i] != '\n' && (*s_buff)[i] != 0)
		i++;
	if ((*s_buff)[i] == '\n')
		i++;
	line = ft_substr(*s_buff, 0, i);
	tmp_buff = ft_substr(*s_buff, i, ft_strlen(*s_buff));
	free(*s_buff);
	*s_buff = tmp_buff;
	return (line);
}

static void	get_reader(int fd, char **s_buff)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_buff;

	if (BUFFER_SIZE < 0 || BUFFER_SIZE > 8000000)
		return ;
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!*s_buff)
			tmp_buff = ft_strdup(buff);
		else
			tmp_buff = ft_strjoin(*s_buff, buff);
		free (*s_buff);
		*s_buff = tmp_buff;
		if (ft_strchr(*s_buff, '\n'))
			return ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*s_buff[1024];
	char		*line;

	if (BUFFER_SIZE < 0 || BUFFER_SIZE > 8000000)
		return (NULL);
	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	if (!s_buff[fd] || !(ft_strchr(s_buff[fd], '\n')))
		get_reader(fd, (&s_buff[fd]));
	line = get_line(&s_buff[fd]);
	return (line);
}

//	--------------------------------------------------------------------------//
//	get_next_line bonus will still only use only one static variable and read
//	from multiple fd's
//	Only difference is, we fill our buffer with an array of size 1024 (maximum
//	number of fd's that can be opened at once)
//	Malloc frees are doing accordingly in get_line
//	--------------------------------------------------------------------------//
