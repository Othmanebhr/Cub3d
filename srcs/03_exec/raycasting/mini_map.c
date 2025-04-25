/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:37 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 19:01:28 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	size = MINIMAP_SCALE;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (x + i >= 0 && x + i < WINDOW_WIDTH
				&& y + j >= 0 && y + j < WINDOW_HEIGHT)
				*(int *)(game->img.addr \
					+ ((y + j) * game->img.line_len
					+ (x + i) * (game->img.bits_per_pixel / 8))) = color;
	}
}

void	draw_minimap(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == '1')
				color = 0x888888;
			else if (game->map.grid[i][j] == '0')
				color = 0x222222;
			else
				color = 0x000000;
			draw_square(game, MINIMAP_OFFSET_X + j * MINIMAP_SCALE, \
				MINIMAP_OFFSET_Y + i * MINIMAP_SCALE, color);
		}
	}
	draw_square(game,
		MINIMAP_OFFSET_X + (int)(game->player.pos.x * MINIMAP_SCALE),
		MINIMAP_OFFSET_Y + (int)(game->player.pos.y * MINIMAP_SCALE),
		0xFF0000);
}
