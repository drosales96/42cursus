/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:35:56 by sternero          #+#    #+#             */
/*   Updated: 2024/09/16 13:03:05 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* LIBS */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*  MY OWN LIBS */

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

/* MLX */

# include "../MLX42/include/MLX42/MLX42.h"
# include "./MLX42/MLX42.h"

/* TITTLE OF THE CREATION */

# define NAME "so_long"
# define TITRE "So Long"

# define TILE_SIZE 32
# define IMG_SIZE 48

/* WINDOWS SIZE */

# define WIDTH 1920
# define HEIGHT 1080

/* BOOLEAN VALUES */

# define TRUE 1
# define FALSE 0
# define BOOL

/* DEFINING BUFFERSIZE FOR GNL */

# define BUFFER_SIZE 1042

/* ELEMENTS OF THE GAME */

# define PLAYER 'P'
# define ENEMY 'X'
# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define EXIT 'E'

/* ERRORS */

# define ERR_FILE "Invalid name of the map, must be a *.ber file\n"
# define ERR_CHAR "The map contains invalid characters.\n"
# define ERR_MLX "Failed MLX initiation.\n"
# define ERR_MAP "The map was not found or cannot be opened.\n"
# define ERR_INIT "Usage: ./so_long [map.ber].\n"
# define ERR_PLAYER "The map must contain one player (ship), and only one.\n"
# define ERR_COLLEC "The map must contain at least one collectible.\n"
# define ERR_EXIT "The map must contain one exit, and only one.\n"
# define ERR_FORMAT "The map is not rectangular.\n"
# define ERR_BORDER "The map must be surrounded by walls.\n"
# define ERR_LINE "Empty line has been detected in the file.\n"
# define ERR_GENERAL "Map or objects failed.\n"

/* RETURN VALUES */

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

/* ASCII KEY ARROWS */

# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362

# define ESC 65307

/* STRUCT FOR TEXTURES */

typedef struct s_txts
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
	mlx_texture_t	*character;
	mlx_texture_t	*character_u;
	mlx_texture_t	*character_d;
	mlx_texture_t	*character_l;
	mlx_texture_t	*character_r;
	mlx_texture_t	*npc;
}	t_txts;

/* STRUCT FOR IMGS */

typedef struct s_images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collec;
	mlx_image_t		*exit_c;
	mlx_image_t		*exit_o;
	mlx_image_t		*character;
	mlx_image_t		*character_u;
	mlx_image_t		*character_d;
	mlx_image_t		*character_l;
	mlx_image_t		*character_r;
	mlx_image_t		*npc;
}	t_images;

/* STRUCT FOR THE MAP */

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}	t_map;

/* STRUCT FOR COLS AND ROWS */

typedef struct s_cell
{
	int	character;
	int	npc;
	int	floor;
	int	wall;
	int	collec;
	int	exit;
}	t_cell;

/* STRUCT FOR KEY ARROWS */

typedef struct s_key_press
{
	int	key;
}	t_key_press;

/* COORDENADES */

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

/* FOR IMG, TEXT AND COUNTING ELEMENTS */
typedef struct s_init
{
	mlx_t			*mlx;
	t_txts			txts;
	t_images		imgs;
	t_cell			cell;
	t_map			*map;
	t_coord			character;
	t_coord			size;
	char			**status_a;
	char			**status_b;
	char			*path;
	int				moves;
	int				counter;
	int				collec;
	int				c;
	int				flag;
	char			course;
	bool			walking;
}	t_init;

t_init		**ft_fill(char **stat, t_coord size, t_coord now, t_init **game);
t_init		*ft_flood(t_init *game);
int			ft_check_cells(t_cell checked, t_cell elements);
int			ft_check_main_elements(t_cell objects);
int			ft_map_shape(t_init *game);
int			ft_check_borders(t_init *game);
int			ft_check_all(t_init *game, t_cell objects);
int			ft_checking_file(char *file);
void		ft_check_empty_line(t_init *game, char *line);
t_init		**ft_check_cell(t_init	**game, char check);
int			ft_key_check(t_init *game);
void		ft_char_to_up(t_init *game, t_coord p, int step);
void		ft_char_to_down(t_init *game, t_coord p, int step);
void		ft_char_to_right(t_init *game, t_coord p, int step);
void		ft_char_to_left(t_init *game, t_coord p, int step);
t_map		*ft_add_line(char *line);
void		ft_last_line(t_init *game, t_map *new);
void		ft_print_matrix(t_init *game);
void		ft_drawing_imgs(t_init *game, char img, t_coord p);
void		ft_drawing_char(t_init *game, t_coord p);
void		ft_free(t_init *game, int error);
void		ft_free_stack(t_map **stack);
void		ft_free_textures(t_init **game);
void		ft_free_images(t_init **game);
char		**ft_free_status(char **status, int len);
t_init		*ft_initialize_game(t_init *init);
int			ft_start_map(char *path);
t_map		*ft_map_init(t_init *game);
void		ft_init_txts(t_init *game);
void		ft_init_imgs(t_init *game);
t_init		*ft_find_character(t_init *ship);
void		ft_objs_init(t_cell *obj);
t_cell		ft_count_obj(t_map *map);
void		ft_mlx_init(t_init *gm);
void		ft_move_char_right(t_init *game, int y, int x);
void		ft_move_char_left(t_init *game, int y, int x);
void		ft_move_char_up(t_init *game, int y, int x);
void		ft_move_char_down(t_init *game, int y, int x);
int			ft_map_x(t_map *width);
int			ft_map_y(t_map *height);
char		**ft_status_map(t_init *game);
void		ft_key_press(struct mlx_key_data key_data, void *date);
int			ft_map(t_init **game);
char		*get_next_line(int fd);

/* TERMINAL COLORS */

# define WHITE "\033[1;37m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define DARK_YELLOW "\033[1;93m"
# define BLUE "\033[1;34m"
# define DARK_BLUE "\033[1;36m"
# define MAGENTA "\033[1;35m"
# define PEACH "\033[1;91m"
# define CYAN "\033[1;36m"
# define PINK "\033[1;95m"
# define RESET "\033[0m"
# define SLOW_BLINK "\033[5m"

#endif