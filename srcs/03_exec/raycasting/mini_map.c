/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:59:37 by besch             #+#    #+#             */
/*   Updated: 2025/04/26 17:08:02 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pad_map_lines_with_spaces(char **grid, int height, int width, t_gc *gc)
{
	int		i;
	int		len;
	char	*new_line;

	i = -1;
	while (++i < height)
	{
		len = ft_strlen(grid[i]);
		if (len < width)
		{
			new_line = gc_malloc(width + 1, gc);
			ft_memcpy(new_line, grid[i], len);
			ft_memset(new_line + len, ' ', width - len);
			new_line[width] = '\0';
			grid[i] = new_line;
		}
	}
}

static void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINIMAP_SCALE)
	{
		j = -1;
		while (++j < MINIMAP_SCALE)
		{
			if (x + i >= 0 && x + i < WINDOW_WIDTH
				&& y + j >= 0 && y + j < WINDOW_HEIGHT)
				*(int *)(game->img.addr + ((y + j) * game->img.line_len \
				+ (x + i) * (game->img.bits_per_pixel / 8))) = color;
		}
	}
}

static int	get_minimap_color(t_game *game, int map_x, int map_y)
{
	if (map_x >= 0 && map_x < game->map.width
		&& map_y >= 0 && map_y < game->map.height)
	{
		if (game->map.grid[map_y][map_x] == '0'
			|| game->map.grid[map_y][map_x] == 'N'
			|| game->map.grid[map_y][map_x] == 'S'
			|| game->map.grid[map_y][map_x] == 'E'
			|| game->map.grid[map_y][map_x] == 'W')
			return (0x888888);
		else
			return (0x000000);
	}
	return (0x000000);
}

static void	draw_minimap_tiles(t_game *game, int center)
{
	int	i;
	int	j;
	int	map_x;
	int	map_y;
	int	color;

	i = -1;
	while (++i < MINIMAP_SIZE)
	{
		j = -1;
		while (++j < MINIMAP_SIZE)
		{
			map_x = (int)game->player.pos.x + (j - center);
			map_y = (int)game->player.pos.y + (i - center);
			color = get_minimap_color(game, map_x, map_y);
			draw_square(game,
				MINIMAP_OFFSET_X + j * MINIMAP_SCALE,
				MINIMAP_OFFSET_Y + i * MINIMAP_SCALE,
				color);
		}
	}
}

void	draw_minimap(t_game *game)
{
	int	center;

	center = MINIMAP_SIZE / 2;
	pad_map_lines_with_spaces(game->map.grid,
		game->map.height, game->map.width, &game->gc);
	draw_minimap_tiles(game, center);
	draw_square(game,
		MINIMAP_OFFSET_X + center * MINIMAP_SCALE,
		MINIMAP_OFFSET_Y + center * MINIMAP_SCALE,
		0xFF0000);
}
