/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:08:01 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/23 11:39:29 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (ray->map_x + 1.0 - player->pos.x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (ray->map_y + 1.0 - player->pos.y) * ray->delta_dist_y;
	}
}

static void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist
			= (ray->map_x - player->pos.x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist
			= (ray->map_y - player->pos.y + (1 - ray->step_y) / 2) / ray->dir_y;
}

static void	draw_wall(t_game *game, t_ray *ray, int x)
{
	// 1. Choisir la texture selon la face touchée
	t_texture *tex;
	if (ray->side == 0 && ray->dir_x > 0)
		tex = &game->textures[EAST];
	else if (ray->side == 0 && ray->dir_x < 0)
		tex = &game->textures[WEST];
	else if (ray->side == 1 && ray->dir_y > 0)
		tex = &game->textures[SOUTH];
	else
		tex = &game->textures[NORTH];

	char *tex_addr = tex->addr;
	int tex_width = tex->width;
	int tex_height = tex->height;
	int texture_line_len = tex->line_len;
	int texture_bpp = tex->bits_per_pixel;

	// 2. Calculer la hauteur de la ligne à dessiner
	int line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	int draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0) draw_start = 0;
	int draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT) draw_end = WINDOW_HEIGHT - 1;

	// 3. Calculer la coordonnée X sur la texture
	double wall_x;
	if (ray->side == 0)
		wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)tex_width);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
		tex_x = tex_width - tex_x - 1;

	// 4. Boucle pour chaque pixel vertical du mur
	for (int y = draw_start; y < draw_end; y++)
	{
		int d = y * 256 - WINDOW_HEIGHT * 128 + line_height * 128;
		int tex_y = ((d * tex_height) / line_height) / 256;
		int color = *(int *)(tex_addr + (tex_y * texture_line_len + tex_x * (texture_bpp / 8)));
		*(int *)(game->img.addr + (y * game->img.line_len + x * (game->img.bits_per_pixel / 8))) = color;
	}
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	color_handle(game);
	while (x < WINDOW_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step_and_side_dist(&ray, &game->player);
		perform_dda(&ray, &game->map);
		calculate_wall_distance(&ray, &game->player);
		draw_wall(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
