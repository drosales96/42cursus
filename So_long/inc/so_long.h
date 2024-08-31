/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:35:01 by drosales          #+#    #+#             */
/*   Updated: 2024/08/31 19:50:27 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* COMMON USE LIBRARIES */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

/* GRAPHICS LIBRARY PATH*/

# include "../MLX42/include/MLX42/MLX42.h"

/* MY OWN UTILS LIBRARIES */

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/* WINDOW EXE NAME*/

# define TITRE "So long"

/* WIDTH & HEIGHT */

# define WIDTH 1092
# define HEIGHT 1080

/* TILES DIMESIONS */

# define TILE_SIZE 32

/* BUFFER SIZE NEEDED FOR GNL */

# define BUFFER_SIZE 1042

/* ERROR MESSAGES */

# define FILE_ERROR "⛔ The file has incorrect format. It should be *.ber\n"
# define MATRIX_CHAR_ERROR "⛔ The map contain an incorrect character\n"
# define MATRIX_LINE_ERROR "⛔ There is an error in the matrix lines lenght\n"
# define LINE_ERROR "⛔ There is an error about lines\n"
# define WALL_ERROR "⛔ There are no limits, FATAL ERROR"
# define ELEMENTS_ERROR "⛔ There is/are wrong/s element/s inside the matrix\n"
# define ARG_ERROR "⛔ Incorrect quantity of arguments\n"
# define ALLOC_ERROR "⛔ No memmory allocs the game"

/* DEFINING MOVEMENT BUTTONS WITH ASCII */

# define LEFT   97 // "A"
# define RIGHT  119 // "D"
# define UP     100 // "W"
# define DOWN   115 // "S"

# define ESC    65907 // "ESC"

/* ALL ELEMENTS THAT ARE INVOLVED (STRUCT) */

typedef struct s_elements
{
    void    *mlx;
    void    *mlx_window;
    void    *player;
    void    *player_P;
    void    *pl_move;
    void    *pl_left;
    void    *pl_left_mv;
    void    *pl_right;
    void    *pl_right_move;
    void    *pl_back;
    void    *pl_back_mv;
    void    *background;
    void    *limit_element;
    void    *exit;
    void    *npc;
    int     error;
    int     x;
    int     y;
    int     key_arrows;
    int     player_control;
    int     lines_control;
    int     collect;
    int     wall;
    int     enemy;
    int     ex;
    int     pl;
    int     backgr;
    int     width_len;
    int     height_len;
    char    *map;

}           t_elements;

/* GNL FUNCTIONS */

char	*get_next_line(int fd);


/* FUNCTIONS NEEDED*/

int     ft_file_checker(char *map, t_elements *data);
void    ft_free(t_elements *data);
void    ft_reading_map(char *file , t_elements *data);

#endif