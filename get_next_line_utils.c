/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:06:11 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/23 19:49:45 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strjoin(char const *s1, char const *s2)
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
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	c = (char)c;
	len = ft_strlen(s);
	if (!c)
		return ((char *)&s[len]);
	while (s[len] != c)
	{
		if (len <= 0)
			return (NULL);
		len--;
	}
	return ((char *)&s[len]);
}