/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:27:50 by drosales          #+#    #+#             */
/*   Updated: 2024/09/02 08:45:10 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void ft_check_lines(t_elements *data)
{
    int i;

    i = 0;
    while (data->map[i] != NULL)
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
        i++;
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

/*

FT_FREE: La función pone la variable ERROR en 1 para determinar que
efectivamente hay un error y libera tanto data, como data->map.

FT_CHECK_LINES_FINAL: La función se encarga de analizar cada caracter
en busca de el salto de linea correspondiente a cada línea, excepto la
final que no lo va a tener. Cada vez que ve un '\n' se actualiza a '0'
para indicar que se encuentra el caracter de salto de línea.

FT_CHECK_LIMITS_LINES: Esta función primeramente extrae la información
de la primera línea, ya que comprueba si encuentra '1' y '\n', lo que
indicaría que la primera línea está correcta. Después mediante una opera-
ción que sería FT_ STRLEN (LONGITUD_TOTAL_MAPA_UNILINEAL) - LONGITUD DE
LA PRIMERA LÍNEA, no proporciona la posición del primer caracter de la
última línea, para así comprobar efectivamente que se componga de '1' y
de '\n'.

FT_CHECK_LINES: La función recorre cada caracter del mapa para verificar
que se componga de '1', '0', 'P', 'C', 'E'.

*/