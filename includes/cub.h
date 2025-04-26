/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:04:44 by besch             #+#    #+#             */
/*   Updated: 2025/04/26 17:40:28 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* -------------------------------------------------------------------------- */
/*                                  INCLUDES                                  */
/* -------------------------------------------------------------------------- */

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../my_lib/includes/gc.h"
# include "../my_lib/includes/get_next_line_bonus.h"
# include "../my_lib/includes/libft.h"
# include "../minilibx-linux/mlx.h"

/* -------------------------------------------------------------------------- */
/*                                  DEFINES                                   */
/* -------------------------------------------------------------------------- */

// COLORS
# define COLOR_ENABLED 1
# if COLOR_ENABLED
#  define DEFAULT "\001\033[0m"
#  define RED "\001\033[1;31m"
#  define GREEN "\033[1;32m\002"
#  define YELLOW "\001\033[1;33m"
#  define BLUE "\001\033[1;34m"
#  define MAGENTA "\001\033[1;35m"
#  define ROSE "\001\033[1;95m"
#  define CYAN "\033[1;36m\002"
#  define WHITE "\001\033[1;37m"
# else
#  define DEFAULT ""
#  define RED ""
#  define GREEN ""
#  define YELLOW ""
#  define BLUE ""
#  define MAGENTA ""
#  define ROSE ""
#  define CYAN ""
#  define WHITE ""
# endif

// WINDOW SETTINGS
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "Cub3D"

// GAMEPLAY SETTINGS
# define MOVE_SPEED 0.04
# define ROT_SPEED 0.04
# define COLLISION_PADDING 0.2

// MAP SETTINGS
# define MAX_MAP_WIDTH 512
# define MAX_MAP_HEIGHT 512

// TEXTURE SETTINGS
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NUM_TEXTURES 4

// KEY CODES (Linux X11)
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

// MINIMAP SETTINGS
# define MINIMAP_SCALE 8
# define MINIMAP_SIZE  30
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10

/* -------------------------------------------------------------------------- */
/*                                   ENUMS                                    */
/* -------------------------------------------------------------------------- */

// DIRECTION ENUM
typedef enum e_direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;

/* -------------------------------------------------------------------------- */
/*                                 STRUCTURES                                 */
/* -------------------------------------------------------------------------- */

// PARSE ELEMENTS STRUCTURE
typedef struct s_parsing
{
	char	**tokens;
	bool	found_na;
	bool	found_so;
	bool	found_we;
	bool	found_ea;
	bool	found_floor;
	bool	found_ceiling;
}	t_parsing;

// POINT/VECTOR STRUCTURE
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

// TEXTURE STRUCTURE
typedef struct s_texture
{
	char	*path;
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_texture;

// MAP STRUCTURE
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
}	t_map;

// PLAYER STRUCTURE
typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	t_direction	start_dir;
}	t_player;

// IMAGE STRUCTURE
typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		mouse_last_x;
}	t_img;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}	t_keys;


// GAME STRUCTURE
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_parsing	parsing;
	t_texture	textures[NUM_TEXTURES];
	t_map		map;
	t_player	player;
	t_img		img;
	t_keys		keys;
	t_gc		gc;
}	t_game;


/* ------------------------------------------------------------------------- */
/*                             FUNCTION PROTOTYPES                           */
/* ------------------------------------------------------------------------- */

/* ----------------------------- Initialization ---------------------------- */
int		initialize_game(char *cub_path, t_game *game);

/* -------------------------------- Parsing -------------------------------- */
char	**read_cub_file(int fd, t_game *game);
int		verify_elements(char **lines, t_game *game);
int		handle_texture(t_parsing *pe, t_game *game, int idx);
int		handle_color(t_parsing *pe, t_game *game);
bool	is_map_line(const char *line);
int		parse_map(char **lines, t_game *game);
int		check_map_dimensions(char **lines, int start, int end);
int		check_map_lines(char **lines, int start, int end);
void	replace_spaces_with_one(char **lines, int start, int end);
int		check_player_spawn(char **lines, t_game *game, int start, int end);
int		copy_map_to_game(char **lines, t_game *game, int start, int end);


/* ------------------------------- Utilities ------------------------------- */
int		ft_error(char *str);
int		free_game(t_game *game);
int		close_window(t_game *game);

/* ------------------------------------------------------------------------- */
/*                                    OTH                                    */
/* ------------------------------------------------------------------------- */

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}	t_ray;

/*Keyhook*/
int		handle_keyhook(t_game *game);
void	handle_move(t_game *game, t_player *player, t_keys *key);
void	move_if_no_collision(t_game *game, \
t_player *player, double next_x, double next_y);
void	handle_rotation(t_player *player, t_keys *key);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		handle_mouse_move(int x, int y, void *param);
int		mouse_motion(int x, int y, t_game *game);

//raycasting
void	raycasting(t_game	*game);
void	color_handle(t_game *game);
void	init_ray(t_ray *ray, t_player *player, int x);
void	perform_dda(t_ray *ray, t_map *map);
void	draw_wall(t_game *game, t_ray *ray, int x, int color, int line_height);
void	draw_minimap(t_game *game);

//init struct
void	init_ray(t_ray *ray, t_player *player, int x);

#endif
