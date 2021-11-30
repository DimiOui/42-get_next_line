/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:03 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/11/30 16:06:05 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		BUFFER_SIZE;
	char	*buff;

	BUFFER_SIZE = 10;
	buff = malloc (sizeof (char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
}
