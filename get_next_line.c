/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/01 11:41:57 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

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
	static char	*sbuff = NULL;

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
