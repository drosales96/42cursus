/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:27:50 by drosales          #+#    #+#             */
/*   Updated: 2024/08/31 19:30:20 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void ft_check_lines(t_elements *data)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(data->map);
    while (i < len)
    {
        if (data->map[i] != '1' || data->map[i] != 'P' || data->map[i] != 'C'
            || data->map[i] != 'E' || data->map[i] != '0')
            exit(ELEMENTS_ERROR);
        else if (data->map[i] == '1')
            data->wall++;
        else if (data->map[i] == '0')
            data->backgr++;
        else if (data->map[i] == 'C')
            data->collect++;
        else if (data->map[i] == 'E')
            data->ex++;
        else if (data->map[i] == 'P')
            data->pl++;
        i--;
    }
}

static void ft_check_limits_lines(t_elements *data)
{
    int i;
    int last;

    i = 0;
    last = ft_strlen(data->map) - data->width_len;
    while (i != data->width_len)
    {
        if (data->map[i] == '1' || data->map[i] == '\n')
            i++;
        else
            exit(WALL_ERROR);
    }
    while (last < data->width_len)
    {
        if (data->map[last] == '1' || data->map[last] == '\n')
            last++;
        else
            exit(WALL_ERROR);
    }
}

static void ft_check_lines_final(t_elements *data, char *line)
{
    int i;

    i = 0;
    data->lines_control = 1;
    while (line[i])
    {
        if (line[i] == '\n')
            data->lines_control = 0;
        i++;
    }
}

void    ft_reading_map(char *file , t_elements *data)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        ft_free(data);
    data->lines_control = 2;
    while (data->lines_control != 1)
    {
        data->height_len++;
        line = get_next_line(fd);
        if (!line)
            exit(LINE_ERROR);
        if (data->lines_control == 2)
            data->width_len = ft_strlen(line);
        ft_check_lines_final(data, line);
        if (ft_strlen(line) + data->lines_control != data->width_len)
            exit (MATRIX_LINE_ERROR);
        data->map = ft_strjoin(data->map, line);
        if (line)
            free(line);
    }
    close(fd);
    ft_check_limits_lines(data);
    ft_check_lines(data);
}