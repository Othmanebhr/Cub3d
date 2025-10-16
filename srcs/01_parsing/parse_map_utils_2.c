/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:43 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 16:57:42 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_map_dimensions(char **lines, int start, int end)
{
	int	i;
	int	width;
	int	height;

	height = end - start + 1;
	if (height > MAX_MAP_HEIGHT)
		return (ft_error("Error\nMap too tall (MAX_MAP_HEIGHT exceeded)"));
	i = start - 1;
	while (++i <= end)
	{
		width = ft_strlen(lines[i]);
		if (width > MAX_MAP_WIDTH)
			return (ft_error("Error\nMap too wide (MAX_MAP_WIDTH exceeded)"));
	}
	return (0);
}

void	replace_spaces_with_one(char **lines, int start, int end)
{
	int	i;
	int	j;

	i = start - 1;
	while (++i <= end)
	{
		j = -1;
		while (lines[i][++j])
			if (lines[i][j] == ' ')
				lines[i][j] = '1';
	}
}

int	copy_map_to_game(char **lines, t_game *game, int start, int end)
{
	int	i;
	int	map_height;

	map_height = end - start + 1;
	game->map.grid = gc_malloc(sizeof(char *) * (map_height + 1), &game->gc);
	i = -1;
	while (++i < map_height)
		game->map.grid[i] = ft_strdup_gc(lines[start + i], &game->gc);
	game->map.grid[map_height] = NULL;
	game->map.height = map_height;
	game->map.width = 0;
	i = -1;
	while (++i < map_height)
		if ((int)ft_strlen(game->map.grid[i]) > game->map.width)
			game->map.width = ft_strlen(game->map.grid[i]);
	return (0);
}
