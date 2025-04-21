/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:36:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/21 20:44:26 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_img(t_game *game)
{
	if (game->textures)
	{
		if (game->textures[NORTH].img)
			mlx_destroy_image(game->mlx, game->textures[NORTH].img);
		if (game->textures[SOUTH].img)
			mlx_destroy_image(game->mlx, game->textures[SOUTH].img);
		if (game->textures[WEST].img)
			mlx_destroy_image(game->mlx, game->textures[WEST].img);
		if (game->textures[EAST].img)
			mlx_destroy_image(game->mlx, game->textures[EAST].img);
	}
}

static void	load_texture(t_game *game, int dir, const char *err_msg)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->textures[dir].img
		= mlx_xpm_file_to_image(game->mlx, game->textures[dir].path, &w, &h);
	if (!game->textures[dir].img)
		close_window(game, (char *)err_msg);
	game->textures[dir].width = w;
	game->textures[dir].height = h;
	game->textures[dir].addr = mlx_get_data_addr(game->textures[dir].img, \
										&game->textures[dir].bits_per_pixel, \
										&game->textures[dir].line_len, \
										&game->textures[dir].endian);
}

static void	init_frame_buffer(t_game *game)
{
	int	w;
	int	h;

	w = WINDOW_WIDTH;
	h = WINDOW_HEIGHT;
	game->img.img = mlx_new_image(game->mlx, w, h);
	if (!game->img.img)
		close_window(game, "error: Failed to create frame buffer");
	game->img.addr = mlx_get_data_addr(game->img.img, \
									&game->img.bits_per_pixel, \
									&game->img.line_len, \
									&game->img.endian);
}

void	init_img(t_game *game)
{
	load_texture(game, NORTH, "error: Failed to load NO texture");
	load_texture(game, SOUTH, "error: Failed to load SO texture");
	load_texture(game, WEST, "error: Failed to load WE texture");
	load_texture(game, EAST, "error: Failed to load EA texture");
	init_frame_buffer(game);
}
