/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:43 by rmedina-          #+#    #+#             */
/*   Updated: 2024/01/02 20:02:05 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *str_temp = NULL;
    char *str_return;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if(!str_temp)
    {
        str_temp = malloc(1); // this fucker
        if (str_temp == NULL)
            return NULL;
        str_temp[0] = '\0';
    }
    // printf("28: %s\n", str_temp);
    str_temp = read_gnl(str_temp, fd);
    if (!str_temp)
        return (NULL);
    // printf("30: %s\n", str_temp);
    str_return = get_linee(&str_temp);
    // printf("32: %s\n", str_temp);
    return str_return ;
}
char *read_gnl(char *str_temp, int fd)
{
    char *temp;
    int int_temp;
    char *str_join;
    temp = malloc(BUFFER_SIZE + 1); // this fucker
    if (!temp)
        return NULL;
    temp[0] = '\0';
    int_temp = 1;
    while(!ft_strchr(str_temp, '\n') && int_temp > 0)
    {
        int_temp = read(fd, temp, BUFFER_SIZE);
        if (int_temp == -1)
            return (free(temp), free(str_temp), NULL);
        temp[int_temp] = '\0';
        str_join = strjoin(str_temp, temp);
        free(str_temp);
        str_temp = str_join;
        if (!str_temp)
            return (free(temp), NULL);
    }
    free(temp);
    return (str_temp);
}
char *get_linee(char **str_temp)
{
    char *str_cut;
    char *line;
    char *str_sub;

    str_cut = ft_strchr(*str_temp, '\n');
    if (!str_cut)
        str_cut = *str_temp + ft_strlen(*str_temp);
    line = ft_substr(*str_temp, 0, (size_t)(str_cut - *str_temp) + 1);
    // printf("67: %s\n", str_cut);
    str_sub = ft_substr(*str_temp, (unsigned int)(str_cut - *str_temp) + 1, ft_strlen(*str_temp));
    // printf("69: %s\n", str_sub);
    free(*str_temp);
    *str_temp = str_sub;
    return line;
}
// int main()
// {
//     int fd = open("prueba.txt", O_RDONLY);
//     char *line = get_next_line(fd);
//     while (line)
//     {
//         printf("%s", line);
//         free(line);
//         line = get_next_line(fd);
//     }
//     printf("\n");
//     close(fd);
//     return 0;
// }