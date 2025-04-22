/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:04:44 by besch             #+#    #+#             */
/*   Updated: 2025/04/22 18:57:07 by besch            ###   ########.fr       */
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
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define WINDOW_TITLE "Cub3D"

// GAMEPLAY SETTINGS
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define COLLISION_PADDING 0.1

// MAP SETTINGS
# define MAX_MAP_WIDTH 100
# define MAX_MAP_HEIGHT 100

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
typedef struct s_parse_elements
{
	char	**tokens;
	bool	found_na;
	bool	found_so;
	bool	found_we;
	bool	found_ea;
	bool	found_floor;
	bool	found_ceiling;
}	t_parse_elements;

// POINT/VECTOR STRUCTURE
typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

// COLOR STRUCTURE
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

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

/* // RAY STRUCTURE
typedef struct s_ray
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	t_vec2	ray_dir;
	t_vec2	side_dist;
	t_vec2	delta_dist;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	double	tex_pos;
	int		tex_y;
}	t_ray; */

// MAP STRUCTURE
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_color		floor_color;
	t_color		ceiling_color;
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
	t_img		img;
	t_map		map;
	t_player	player;
	t_texture	textures[NUM_TEXTURES];
	t_keys		keys;
	t_gc		gc;
}	t_game;

/* ------------------------------------------------------------------------- */
/*                             FUNCTION PROTOTYPES                           */
/* ------------------------------------------------------------------------- */

/* ----------------------------- Initialization ---------------------------- */
int		initialize_game(char *cub_path, t_game *game);
// int		load_textures(t_game *game);
// void	init_player(t_game *game);
// int		setup_mlx(t_game *game);

/* -------------------------------- Parsing -------------------------------- */
char	**read_cub_file(int fd, t_game *game);
int		verify_elements(char **lines, t_game *game);
int		handle_texture(t_parse_elements *pe, t_game *game, int idx);
int		handle_color(t_parse_elements *pe, t_game *game);
bool	is_map_line(const char *line);
int		parse_map(char **lines, t_game *game);
int		check_map_lines(char **lines, int start, int end);
int		check_player_spawn(char **lines, t_game *game, int start, int end);
int		copy_map_to_game(char **lines, t_game *game, int start, int end);

/* ------------------------------- Rendering ------------------------------- */
// int		render_frame(t_game *game);
// void	cast_rays(t_game *game);
// void	draw_walls(t_game *game, t_ray *ray, int x);
// void	draw_floor_ceiling(t_game *game);
// void	calculate_ray(t_game *game, t_ray *ray, int x);
// void	perform_dda(t_game *game, t_ray *ray);
// void	calculate_wall_distance(t_ray *ray);
// void	calculate_wall_texture(t_game *game, t_ray *ray);

/* ---------------------------- Player Movement ---------------------------- */
// void	move_player(t_game *game);
// void	move_forward(t_game *game);
// void	move_backward(t_game *game);
// void	move_left(t_game *game);
// void	move_right(t_game *game);
// void	rotate_left(t_game *game);
// void	rotate_right(t_game *game);

/* ------------------------------- Texturing ------------------------------- */
// int		load_texture(t_game *game, t_texture *texture, char *path);
// void	apply_texture(t_game *game, t_ray *ray, int x);

/* ------------------------------ Input Handling --------------------------- */
// int		key_press(int keycode, t_game *game);
// int		key_release(int keycode, t_game *game);
// int		close_window(t_game *game);

/* ------------------------------- Utilities ------------------------------- */
int		ft_error(char *str);
int		free_game(t_game *game);
int		close_window(t_game *game);

/* ------------------------------------------------------------------------- */
/*                                    OTH                                    */
/* ------------------------------------------------------------------------- */



/* typedef struct s_img
{
	void		*NO_img;
	void		*SO_img;
	void		*WE_img;
	void		*EA_img;
	char		*NO_addr;
	char		*SO_addr;
	char		*WE_addr;
	char		*EA_addr;
	int			line_len;
	int			bpp;//a voir
	int			endian;//a voir

	void	*frame_img;
	char	*frame_addr;
	int		frame_bpp;
	int		frame_line_len;
	int		frame_endian;
}	t_img; */



/* typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player; */

// plane = positin de la camera qui va etre perpendiculaire a la direction




typedef struct s_ray
{
	double	camera_x; //coordonee x dans l'espace camera (?)
	double	dir_x; //dir x du rayon
	double	dir_y; //dir y du rayon
	int		map_x; //position x sur la carte
	int		map_y; //postions y sur la carte
	double	side_dist_x; //distance depuis la position actuelle jusqu'au prochain cote y
	double	side_dist_y; //distance depuis la positions actuelle jusqu'au prochain cote x
	double	delta_dist_x; //distance entre deux cote x consecutif
	double	delta_dist_y; //meme chose pour y
	int		step_x; //direction du pas en x (-1 ou 1)
	int		step_y; //same en y
	int		hit; //1 si mur a ete touche, 0 si non
	int		side; // 0 si un cote x a ete touche, 1 si un cote y a ete touche
	double	perp_wall_dist; //distance perpendiculaire du joueur au mur
}	t_ray;



/* typedef struct s_game
{
	void		*mlx;
	void		*win;//window
	t_img		*imgs;
	t_player	*player;
	t_data		*data;
	t_keys		*keys;
}	t_game; */


/*Keyhook*/
int		handle_keyhook(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);

//raycasting
void	raycasting(t_game	*game);

//init struct
void	init_ray(t_ray *ray, t_player *player, int x);

#endif
