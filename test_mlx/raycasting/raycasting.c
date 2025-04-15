/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:08:01 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/15 18:30:50 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) *
										ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) *
										ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) *
										ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) *
										ray->delta_dist_y;
	}
}

static void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - player->pos_x + 
								(1 - ray->step_x) / 2) / ray->dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - player->pos_y + 
								(1 - ray->step_y) / 2) / ray->dir_y;
	}
}

static void	draw_wall(t_game *game, t_ray *ray, int x) //////////////// A normer
{
	int line_height = (int)(HEIGHT / ray->perp_wall_dist);
	int draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0) draw_start = 0;
	int draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT) draw_end = HEIGHT - 1;

	// 1. Choisir la texture selon la face touchée
	char *tex_addr;
	int tex_width = 64; // largeur de la texture (à adapter)
	int tex_height = 64; // hauteur de la texture (à adapter)
	if (ray->side == 0 && ray->dir_x > 0)
		tex_addr = game->imgs->EA_addr;
	else if (ray->side == 0 && ray->dir_x < 0)
		tex_addr = game->imgs->WE_addr;
	else if (ray->side == 1 && ray->dir_y > 0)
		tex_addr = game->imgs->SO_addr;
	else
		tex_addr = game->imgs->NO_addr;
	// 2. Calculer la coordonnée X sur la texture
	double wall_x;
	if (ray->side == 0)
		wall_x = game->player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player->pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)tex_width);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
		tex_x = tex_width - tex_x - 1;
	// 3. Boucle pour chaque pixel vertical du mur
	for (int y = draw_start; y < draw_end; y++)
	{
		int d = y * 256 - HEIGHT * 128 + line_height * 128;
		int tex_y = ((d * tex_height) / line_height) / 256;
		int color = *(int *)(tex_addr + (tex_y * game->imgs->line_len + tex_x * (game->imgs->bpp / 8)));
		mlx_pixel_put(game->mlx, game->win, x, y, color);
	}
}

static void	perform_dda(t_ray *ray, t_data *data)
{
	// Algorithme DDA pour trouver le point d'intersection avec un mur
	while (ray->hit == 0)
	{
		// Sauter au prochain carré de la carte
		if (ray->side_dist_x < ray->side_dist_y)
		{
			// Avancer dans la direction X
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // Touché un côté vertical (Est/Ouest)
		}
		else
		{
			// Avancer dans la direction Y
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // Touché un côté horizontal (Nord/Sud)
		}
		
		// Vérifier si le rayon a touché un mur
		// Assurez-vous que map_x et map_y sont dans les limites de la carte
		if (ray->map_y < 0 || ray->map_x < 0 || 
			ray->map_y >= data->map_height || ray->map_x >= data->map_width ||
			data->map[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1; // Un mur est touché
		}
	}
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	// Parcourir chaque colonne de l'écran
	x = 0;
	while (x < WIDTH)
	{
		// Initialiser le rayon pour cette colonne
		init_ray(&ray, game->player, x);
		// Calculer le pas et les distances initiales
		calculate_step_and_side_dist(&ray, game->player);
		// Exécuter l'algorithme DDA pour trouver le mur
		perform_dda(&ray, game->data);
		// Calculer la distance perpendiculaire
		calculate_wall_distance(&ray, game->player);
		// Dessiner le mur pour cette colonne
		draw_wall(game, &ray, x);
		x++;
	}
}
