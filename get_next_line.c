/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/01 16:29:54 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *s_buff, int ret)
{
	char	*tmp_buff;
	int		i;

	i = 0;
	while (s_buff[i] != '\n' && s_buff[i] != 0)
	{
		if (s_buff[i] == '\n')
		{
			tmp_buff = ft_substr(s_buff, 0, (i + 1));
			free(s_buff);
			s_buff = tmp_buff;
		}
		else if (s_buff[i] == 0)
		{
			tmp_buff = ft_substr(s_buff, 0, (ft_strlen(s_buff) - i));
			free (s_buff);
			s_buff = tmp_buff;
		}
	}
}



void	get_reader(int	fd, char *s_buff)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_buff;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp_buff = ft_strjoin(s_buff, buff);
		free (s_buff);
		s_buff = tmp_buff;
		if (ft_strchr(s_buff, '\n'))
			return ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*s_buff = "";

	if(!(ft_strchr(s_buff, '\n')))
		get_reader(fd, s_buff);
	get_line(s_buff, ret);
}

/*
int		get_len(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*buff;

	buff = malloc (sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	if (ft_strchr(buff, '\n'))
	{
		buff = ft_substr(buff, 0, get_len(buff));
	};
	buff[ret] = '\0';
	return (buff);
}
*/
