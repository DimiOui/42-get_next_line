/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsemel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:05:01 by jsemel            #+#    #+#             */
/*   Updated: 2021/12/06 12:10:29 by jsemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

int	main (int ac, char **av)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		fd42;
	char	*line;
	char	*line1;
	char	*line42;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	fd2 = open(av[3], O_RDONLY);

	/* STANDARD INPUT*/

	if (!av[1])
	{
		close(fd);
		fd = 0;
	}

	/* TEST WITH MULTIPLE FD */

	printf("\nfd = %d\n", fd);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("\nfd1 = %d\n", fd1);
	if (fd1)
	{
		while ((line1 = get_next_line(fd1)))
		{
			printf("%s", line1);
			free(line1);
		}
	}

	/* DISPLAY ONLY ONE LINE */

	printf("\nfd2 = %d\n", fd2);
	printf("%s",(get_next_line(fd2)));


	/* TEST WITH INVALID FD */

	fd42 = 42;
	printf("\nfd42 = %d\n", fd42);
	printf("%s",(line42 = get_next_line(fd42)));
	free(line42);

	close(fd);
	close(fd1);
	close(fd2);
	close(fd42);
}
