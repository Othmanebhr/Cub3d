/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:23:57 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/25 16:06:50 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	fill_line_with_color(t_game *game, int color, int idx_line)
{
	int	x_fill;

	x_fill = 0;
	while (x_fill < WINDOW_WIDTH)
	{
		*(int *)(game->img.addr + (idx_line * game->img.line_len + x_fill
					* (game->img.bits_per_pixel / 8))) = color;
		x_fill++;
	}
}

void	color_handle(t_game *game)
{
	int	color;
	int	idx_line;

	idx_line = 0;
	while (idx_line < WINDOW_HEIGHT)
	{
		if (idx_line < WINDOW_HEIGHT / 2)
			color = game->map.ceiling_color;
		else
			color = game->map.floor_color;
		fill_line_with_color(game, color, idx_line);
		idx_line++;
	}
}
