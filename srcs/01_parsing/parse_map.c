#include "cub.h"

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

static bool	has_map_line_after(char **lines, int i)
{
	while (lines[i])
	{
		if (is_map_line(lines[i]) == true)
			return (true);
		i++;
	}
	return (false);
}

static int	find_map_limits(char **lines, int *start, int *end)
{
	int	i;

	*start = -1;
	i = -1;
	while (lines[++i])
	{
		if (*start == -1 && is_map_line(lines[i]) == true)
			*start = i;
		else if (*start != -1
			&& (is_map_line(lines[i]) == false || lines[i][0] == '\0'))
		{
			if (has_map_line_after(lines, i + 1) == true)
				return (ft_error
					("Error\nEmpty line inside map is not allowed"));
			*end = i - 1;
			return (0);
		}
	}
	if (*start != -1)
	{
		*end = i - 1;
		return (0);
	}
	return (1);
}

int	parse_map(char **lines, t_game *game)
{
	int	start;
	int	end;

	if (find_map_limits(lines, &start, &end) != 0)
		return (1);
	if (check_map_lines(lines, start, end) != 0)
		return (1);
	if (check_player_spawn(lines, game, start, end) != 0)
		return (1);
	if (copy_map_to_game(lines, game, start, end) != 0)
		return (1);
	if (is_map_closed(game->map.grid, game->map.height) != 0)
		return (1);
	return (0);
}
