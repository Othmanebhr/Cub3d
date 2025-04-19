#include "cub.h"

static bool	is_map_char_ok(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_line_valid(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (is_map_char_ok(line[i]) == false)
			return (false);
	return (true);
}

static bool	is_line_full_of_ones(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ')
			return (false);
	return (true);
}

int	check_map_lines(char **lines, int start, int end)
{
	int	i;

	i = start - 1;
	while (++i <= end)
	{
		if (lines[i][0] == '\0')
			return (ft_error("First/last map line must be only 1 and spaces"));
		if (is_line_valid(lines[i]) == false)
			return (ft_error("Error\nInvalid character in map"));
	}
	if (is_line_full_of_ones(lines[start]) == false
		|| is_line_full_of_ones(lines[end]) == false)
		return (ft_error
			("Error\nFirst/last map line must be only 1 and spaces"));
	return (0);
}

int	copy_map_to_game(char **lines, t_game *game, int start, int end)
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
