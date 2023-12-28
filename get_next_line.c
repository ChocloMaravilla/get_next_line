/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:43 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/28 20:43:13 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char str_temp = NULL;
    char *str_return;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if(!str_temp)
    {
        str_temp = malloc(1 * sizeof (char));
        if(str_temp == NULL)
            return NULL;
    }
    read_gnl(str_temp, fd);


    return str_return ;
}
char *read_gnl(char *str_temp, int fd)
{
    char *temp;
    int int_temp;
    temp = malloc(BUFFER_SIZE + 1 * sizeof (char));
    if(temp == NULL)
        return NULL;
    while(!strrchr(temp, '\n'))
    {
        int_temp = read(fd, temp, BUFFER_SIZE);
        if(int_temp == -1)
            return NULL;
        temp[int_temp] = '\0';
        if(int_temp == 0)
            break;
        str_temp = strjoin(*temp, *str_temp);
    }
    free(temp);
    return str_return;
}
int main()
{
    int fd = open("prueba.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("%s\n", line);
    close(fd);
    return 0;
}