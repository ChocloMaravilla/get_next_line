/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:43 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/11 20:56:18 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char str_return[BUFFER_SIZE + 1];
    read(fd, str_return, BUFFER_SIZE);
    str_return[BUFFER_SIZE] = '\0';
    return str_return ;
}
int main()
{
    int fd = open("prueba.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("%s\n", line);
    close(fd);
    return 0;
}