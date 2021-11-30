/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/11/30 18:06:38 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;
	int		ret;
	char	*buff;

	BUFFER_SIZE = 10;
	buff = malloc (sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	return (buff);
}
