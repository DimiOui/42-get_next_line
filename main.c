/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:08:26 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/11/30 16:26:46 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
    int fd;
    (void)ac;
    fd = open(av[1], O_RDONLY);
	char	*test = get_next_line(fd);
	printf ("%s\n", test);
    close(fd);
    return (0);
}
