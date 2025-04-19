#include "cub.h"

static bool	is_rgb_ok(char *str, t_color *color, t_game *game)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split_gc(str, ',', &game->gc);
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (false);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	color->r = r;
	color->g = g;
	color->b = b;
	return (true);
}

static bool	is_texture_file_ok(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

int	handle_texture(t_parse_elements *pe, t_game *game, int idx)
{
	bool	*found;

	if (idx == 0)
		found = &pe->found_na;
	else if (idx == 1)
		found = &pe->found_so;
	else if (idx == 2)
		found = &pe->found_we;
	else if (idx == 3)
		found = &pe->found_ea;
	else
		return (ft_error("Error\nInvalid texture index"));
	if (*found)
		return (ft_error("Error\nDuplicate texture"));
	*found = true;
	if (is_texture_file_ok(pe->tokens[1]) == false)
		return (ft_error("Error\nTexture file not accessible"));
	game->textures[idx].path = ft_strdup_gc(pe->tokens[1], &game->gc);
	return (0);
}

int	handle_color(t_parse_elements *pe, t_game *game)
{
	if (ft_strncmp(pe->tokens[0], "F", 1) == 0)
	{
		if (pe->found_floor)
			return (ft_error("Error\nDuplicate floor color"));
		pe->found_floor = true;
		if (is_rgb_ok(pe->tokens[1], &game->map.floor_color, game) == false)
			return (ft_error("Error\nInvalid floor color format"));
	}
	else if (ft_strncmp(pe->tokens[0], "C", 1) == 0)
	{
		if (pe->found_ceiling)
			return (ft_error("Error\nDuplicate ceiling color"));
		pe->found_ceiling = true;
		if (is_rgb_ok(pe->tokens[1], &game->map.ceiling_color, game) == false)
			return (ft_error("Error\nInvalid ceiling color format"));
	}
	return (0);
}
