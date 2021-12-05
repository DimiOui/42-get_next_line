/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/05 18:18:23 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	**get_init(char **s_buff)
{
	int	i;

	s_buff = (char **) malloc (sizeof (char *) * MAX_FD);
	if (!s_buff)
		return (NULL);
	i = 0;
	while (i < MAX_FD)
	{
		s_buff[i] = NULL;
		i++;
	}
	return (s_buff);
}

static int	free_fds(char **s_buff)
{
	int	i;

	i = 0;
	while (i < MAX_FD)
	{
		if (s_buff[i] != NULL)
			return (0);
		i++;
	}
	free (s_buff);
	return (1);
}

static char	*get_line(char **s_buff)
{
	char	*line;
	char	*tmp_buff;
	int		i;

	if (!*s_buff || (*s_buff)[0] == '\0')
		return (NULL);
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

	if (BUFFER_SIZE > 8000000)
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
	static char	**s_buff = NULL;
	char		*line;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	if (s_buff == NULL)
		s_buff = get_init(s_buff);
	if (!s_buff[fd] || !(ft_strchr(s_buff[fd], '\n')))
		get_reader(fd, (&s_buff[fd]));
	line = get_line(&s_buff[fd]);
	if (line == NULL)
	{
		free (s_buff[fd]);
		s_buff[fd] = NULL;
		if (free_fds(s_buff) == 1)
			s_buff = NULL;
	}
	return (line);
}
