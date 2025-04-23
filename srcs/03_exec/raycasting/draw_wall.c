/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:58 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/23 17:43:40 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_texture	*choose_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (&game->textures[EAST]);
	else if (ray->side == 0 && ray->dir_x < 0)
		return (&game->textures[WEST]);
	else if (ray->side == 1 && ray->dir_y > 0)
		return (&game->textures[SOUTH]);
	else
		return (&game->textures[NORTH]);
}

static void	calc_wall_params(t_ray *ray, int *l_hgt, int *d_start, int *d_end)
{
	*l_hgt = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	*d_start = -(*l_hgt) / 2 + WINDOW_HEIGHT / 2;
	if (*d_start < 0)
		*d_start = 0;
	*d_end = *l_hgt / 2 + WINDOW_HEIGHT / 2;
	if (*d_end >= WINDOW_HEIGHT)
		*d_end = WINDOW_HEIGHT - 1;
}

static int	calc_tex_x(t_game *game, t_ray *ray, t_texture *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.pos.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x, int color, int line_height)
{
	t_texture	*tex;
	t_vec2		tex_x_y;
	int			draw_start;
	int			draw_end;
	int			dist;

	tex = choose_texture(game, ray);
	tex_x_y.x = calc_tex_x(game, ray, tex);
	calc_wall_params(ray, &line_height, &draw_start, &draw_end);
	while (draw_start < draw_end)
	{
		dist = draw_start * 256 - WINDOW_HEIGHT * 128 + line_height * 128;
		tex_x_y.y = ((dist * tex->height) / line_height) / 256;
		color = *(int *)(tex->addr + ((int)tex_x_y.y \
		* tex->line_len + (int)tex_x_y.x * (tex->bits_per_pixel / 8)));
		*(int *)(game->img.addr + (draw_start * game->img.line_len + x \
			* (game->img.bits_per_pixel / 8))) = color;
		draw_start++;
	}
}
