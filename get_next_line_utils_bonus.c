/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:40 by dpaccagn          #+#    #+#             */
/*   Updated: 2021/12/06 12:49:46 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*target;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	target = malloc(sizeof(char) * size + 1);
	if (!target)
		return (NULL);
	while (src[i])
	{
		target[i] = src[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*target;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	target = malloc (sizeof (char) * len);
	if (!target)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		target[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		target[i + j] = s2[j];
		j++;
	}
	target[i + j] = '\0';
	return (target);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*target;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	target = malloc(sizeof(char) * len + 1);
	if (!target)
		return (NULL);
	while (start--)
		s++;
	i = 0;
	while (i < len)
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
