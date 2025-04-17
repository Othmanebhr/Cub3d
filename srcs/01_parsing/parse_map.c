#include "cub.h"

static int	copy_map_to_game(char **lines, t_game *game, int start, int end)
{
	int	i;
	int	map_height;

	map_height = end - start + 1;
	game->map.grid = gc_malloc(sizeof(char *) * (map_height + 1), &game->gc);
	if (!game->map.grid)
		return (ft_error("Error\nMalloc failed for map"));
	i = -1;
	while (++i < map_height)
		game->map.grid[i] = ft_strdup_gc(lines[start + i], &game->gc);
	game->map.grid[map_height] = NULL;
	game->map.height = map_height;
	game->map.width = 0;
	i = -1;
	while (++i < map_height)
	{
		if ((int)ft_strlen(game->map.grid[i]) > game->map.width)
			game->map.width = ft_strlen(game->map.grid[i]);
	}
	return (0);
}

// Vérifie si une case vide/joueur est bien entourée
static int	is_cell_closed(char **grid, int i, int j, int height)
{
	int	len;

	len = ft_strlen(grid[i]);
	// Bords de la map
	if (i == 0 || j == 0 || i == height - 1 || j == len - 1)
		return (ft_error("Error\nMap not closed (border)"));
	// Vérifie que les lignes adjacentes sont assez longues
	if (j >= (int)ft_strlen(grid[i - 1]) || j >= (int)ft_strlen(grid[i + 1]))
		return (ft_error("Error\nMap not closed (line too short)"));
	// Vérifie autour
	if (grid[i - 1][j] == ' ' || grid[i + 1][j] == ' ' ||
		grid[i][j - 1] == ' ' || grid[i][j + 1] == ' ')
		return (ft_error("Error\nMap not closed (adjacent to space)"));
	return (0);
}

// Vérifie que chaque case vide/joueur est bien entourée
static int	is_map_closed(char **grid, int height)
{
	char	c;
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < height)
	{
		len = ft_strlen(grid[i]);
		j = -1;
		while (++j < len)
		{
			c = grid[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (is_cell_closed(grid, i, j, height) != 0)
					return (-1);
			}
		}
	}
	return (0);
}

static int	find_map_limits(char **lines, int *start, int *end)
{
	*start = 6;
	while (lines[*start] && lines[*start][0] == '\0')
		(*start)++;
	*end = *start;
	while (lines[*end])
		(*end)++;
	(*end)--;
	while (*end > *start && lines[*end][0] == '\0')
		(*end)--;
	return (0);
}

int	parse_map(char **lines, t_game *game)
{
	int	start;
	int	end;

	find_map_limits(lines, &start, &end);
	if (check_map_lines(lines, start, end) != 0)
		return (1);
	if (copy_map_to_game(lines, game, start, end) != 0)
		return (1);
	if (is_map_closed(game->map.grid, game->map.height) != 0)
		return (1);
	return (0);
}
