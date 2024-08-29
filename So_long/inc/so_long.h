/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:35:01 by drosales          #+#    #+#             */
/*   Updated: 2024/08/29 20:26:39 by drosales         ###   ########.fr       */
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

#define TILE_SIZE 32

/* BUFFER SIZE NEEDED FOR GNL */

#define BUFFER_SIZE 1042

/* ERROR MESSAGES */

# define FILE_ERROR "⛔ The file has incorrect format. It should be *.ber\n"
# define MATRIX_ERROR "⛔ The map contain an incorrect character\n"
# define LINE_ERROR "⛔ There is an empty line in the matrix\n"

/* DEFINING MOVEMENT BUTTONS WITH ASCII */

# define LEFT   97 // "A"
# define RIGHT  119 // "D"
# define UP     100 // "W"
# define DOWN   115 // "S"

# define ESC    65907 // "ESC"

/* Structure for de coordinates (array 2D) */

typedef struct s_matrix
{
    int                 x;
    int                 y;
}                       t_matrix;

/* Structure with a pointer to the map *.ber */

typedef struct s_map
{
    char                *map;
    struct s_map        *next;
}                       t_map;

/* Structure with the textures for all elements */

typedef struct s_textures
{
    mlx_texture_t       *grass;
    mlx_texture_t       *wall;
    mlx_texture_t       *character;
    mlx_texture_t       *character_u;
    mlx_texture_t       *character_d;
    mlx_texture_t       *character_l;
    mlx_texture_t       *character_r;
    mlx_texture_t       *enemy;
    mlx_texture_t       *collect;
    mlx_texture_t       *exit;
}                       t_textures;

/* Structure with a pointer to the images of the library */

typedef struct s_images
{
    mlx_image_t         *grass;
    mlx_image_t         *wall;
    mlx_image_t         *character;
    mlx_image_t         *character_u;
    mlx_image_t         *character_d;
    mlx_image_t         *character_l;
    mlx_image_t         *character_r;
    mlx_image_t         *enemy;
    mlx_image_t         *collect;
    mlx_image_t         *exit;
}                       t_images;

/* Structure to de elements/cells of the Array */

typedef struct s_elements
{
    int                 grass;
    int                 wall;
    int                 character;
    int                 enemy;
    int                 collect;
    int                 exit;
}                       t_elements;

/* Structure for the arrow keys */

typedef struct s_buttons
{
    int                 buttons;
}                       t_buttons;

/* Structure of the game */

typedef struct s_init
{
    mlx_t               *mlx; // CONECTION WITH MLX LIB
    t_textures          text; // TEXTURES
    t_images            img; // IMAGES OF THE GAME
    t_map               *map; //MAP OF THE GAME
    t_matrix            character; // MAIN CHARACTER
    t_matrix            enemy; // ENEMY
    t_matrix            size; // SIZE OF THE WINDOW
    int                 moves; // NUMBER OF MOVES
    int                 c_counter; // COLLECT. COUNTER
    int                 collect; // COLLECT.
    int                 collect_done; // THE COLLECT. THAT ARE ALREADY CATCH
    int                 result; // MSG WIN, LOSE OR GAME
    char                course; // DIRECTION OF THE PLAYER
    bool                walking; // FOR WALKING OR NOT
}                       t_init;

char	                *get_next_line(int fd);

#endif