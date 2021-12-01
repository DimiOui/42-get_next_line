/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:53 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/01 10:22:03 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
//	calculates the length of a string
char	*ft_strdup(const char *src);
//	duplicates a string into another one with malloc (used in substr)
char	*ft_strchr(const char *s, int c);
//	locates the first occurence of c in the s string and returns
//the end of the string from c
char	*ft_strjoin(const char *s1, const char *s2);
//	joins s1 and s2 together by malloccing a new target string
char	*ft_substr(const char *s, unsigned int start, size_t len);
//	Copies a string form start, and  of the  len size len
#endif
