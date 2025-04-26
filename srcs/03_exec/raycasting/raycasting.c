/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:08:01 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/26 17:23:56 by besch            ###   ########.fr       */
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

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;
	int		color;
	int		line_height;

	x = 0;
	color = 0;
	line_height = 0;
	color_handle(game);
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step_and_side_dist(&ray, &game->player);
		perform_dda(&ray, &game->map);
		calculate_wall_distance(&ray, &game->player);
		draw_wall(game, &ray, x, color, line_height);
		x++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
