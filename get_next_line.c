/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/02 12:11:18 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **s_buff)
{
	char	*line;
	char	*tmp_buff;
	int		i;

	i = 0;
	if ((*s_buff[0]) == '\0')
		return (NULL);
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

//	--------------------------------------------------------------------------//
//	get_line will return NULL if s_buff is empty							  //
//	else, we enter a loop where we iterate through s_buff with our index 'i'  //
//	as we encounter a line break, or the end of s_buff.						  //
//	if s_buff is a line break, i++ will allow us to start from AFTER the line //
//	break the next time we call s_buff. We then fill line correctly with	  //
//	s_buff. Finally, we fill the remainder to tmp_buff to free s_buff, then	  //
//	refill it again. Line is then returned.									  //
//	--------------------------------------------------------------------------//

static void	get_reader(int fd, char **s_buff)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	char	*tmp_buff;

	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		tmp_buff = ft_strjoin((*s_buff), buff);
		if (*s_buff[0] != '\0')
			free (*s_buff);
		(*s_buff) = tmp_buff;
		if (ft_strchr((*s_buff), '\n'))
			return ;
		ret = read(fd, buff, BUFFER_SIZE);
	}
}

//	--------------------------------------------------------------------------//
//	get_reader will read the buffer and store the 'read' cursor in ret a first//
//	time. We then enter our main loop. The loop iterates as long as the ret   //
//	value is greater than zero. So as long as there is something to read	  //
//	(ret = 0 is EOF).														  //
//	buff[ret] = '\0' to notify the end of the buff string					  //
//	We then store all our buffer into a temporary buff to free s_buff of all  //
//	the remains. Then pour back tmp_buff to s_buff.							  //
//	We then look for the next line break into s_buff, and returns the remain- //
//	der. Finally to end the loop, we keep reading in case we didn't encounter //
// a line break or the EOF													  //
//	--------------------------------------------------------------------------//

char	*get_next_line(int fd)
{
	static char	*s_buff = "";
	char		*line;

	if (!(ft_strchr(s_buff, '\n')))
		get_reader(fd, (&s_buff));
	line = get_line(&s_buff);
	return (line);
}

//	--------------------------------------------------------------------------//
//	GNL takes the file descriptor as a parameter and returns the first line   //
//	read until it encounters a line break or the end of the file			  //
//																			  //
//	The first 'if' applies if there's a line break in s_buff. Because s_buff  //
//	is first declared as an empty string, we directly go through 'line = ...' //
//	The funtion will then call get_reader (see get_reader comment)			  //
//	Line is then returned with get_line (see get_line comment)				  //
//	--------------------------------------------------------------------------//
