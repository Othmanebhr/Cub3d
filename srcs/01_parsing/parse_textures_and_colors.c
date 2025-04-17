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

// Partie 2 : Vérification des couleurs
int	verify_colors(char **lines, t_game *game)
{
	char	**tokens;

	// Floor
	tokens = ft_split_gc(lines[4], ' ', &game->gc);
	if (!tokens || !tokens[0] || !tokens[1] || tokens[2])
		return (ft_error("Error\nInvalid floor color line format"));
	if (ft_strncmp(tokens[0], "F", 1) != 0)
		return (ft_error("Error\nFloor color identifier invalid"));
	if (is_rgb_ok(tokens[1], &game->map.floor_color, game) == false)
		return (ft_error("Error\nInvalid floor color format"));

	// Ceiling
	tokens = ft_split_gc(lines[5], ' ', &game->gc);
	if (!tokens || !tokens[0] || !tokens[1] || tokens[2])
		return (ft_error("Error\nInvalid ceiling color line format"));
	if (ft_strncmp(tokens[0], "C", 1) != 0)
		return (ft_error("Error\nCeiling color identifier invalid"));
	if (is_rgb_ok(tokens[1], &game->map.ceiling_color, game) == false)
		return (ft_error("Error\nInvalid ceiling color format"));

	return (0);
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

// Partie 1 : Vérification des textures
int	verify_textures(char **lines, t_game *game)
{
	char	*texture_names[4];
	char	**tokens;
	int		i;

	texture_names[0] = "NO";
	texture_names[1] = "SO";
	texture_names[2] = "WE";
	texture_names[3] = "EA";
	i = -1;
	while (++i < 4)
	{
		tokens = ft_split_gc(lines[i], ' ', &game->gc);
		if (!tokens || !tokens[0] || !tokens[1] || tokens[2])
			return (ft_error("Error\nInvalid texture line format"));
		if (ft_strncmp(tokens[0], texture_names[i], 2) != 0)
			return (ft_error("Error\nTexture order or identifier invalid"));
		if (is_texture_file_ok(tokens[1]) == false)
			return (ft_error("Error\nTexture file not accessible"));
		game->textures[i].path = ft_strdup_gc(tokens[1], &game->gc);
	}
	return (0);
}
