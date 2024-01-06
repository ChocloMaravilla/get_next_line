/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:06:11 by rmedina-          #+#    #+#             */
/*   Updated: 2024/01/06 23:21:53 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*con;

	if (!s1 || !s2)
		return (NULL);
	con = malloc((sizeof(char)) * (((s1len = ft_strlen(s1))
					+(s2len = ft_strlen(s2)) + 1)));
	if (!con)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		con[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		con[i + s1len] = s2[i];
		i++;
	}
	con[i + s1len] = '\0';
	return (con);
}
char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
size_t	ft_strlen(char *c)
{
	size_t	a;

	a = 0;
	if (!c)
		return (0);
	while (c[a] != '\0')
		a++;
	return (a);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	c;

	if (s == NULL)
		return (NULL);
	c = ft_strlen(s);
	if (!s || start >= c)
		return (NULL);
	i = 0;
	if (len > (c - start))
		len = c - start;
	a = (char *)malloc(sizeof(char) * len + 1);
	if (!a)
		return (NULL);
	while (i < len)
		a[i++] = s[start++];
	a[i] = '\0';
	return (a);
}
