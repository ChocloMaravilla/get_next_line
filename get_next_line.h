/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:57 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/23 19:49:54 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *get_next_line(int fd);
char    *fillstorage(char *str);
char	*strjoin(char const *s1, char const *s2);
char    *read_gnl(char *str_temp, int fd);
char	*ft_strrchr(const char *s, int c);

#endif