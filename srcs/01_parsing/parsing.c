#include "cub.h"

char	*read_cub_file(int fd, t_game game)
{
	char	*line;
	char	*content;
	int		ret;

	content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		content = ft_strjoin_gc(content, line, &game.gc);
		free(line);
	}
	return (content);
}

int	parse_cub_file(char *cub_tmp, t_game *game)
{
	char	**lines;
	int		i;

	lines = ft_split_gc(cub_tmp, '\n', &game->gc);
	if (!lines)
		return (ft_error("Error\nFail to split cub file"));
	i = 0;
	while (lines[i])
	{
		if (parse_texture_paths(game, lines[i]) == -1)
			break ;
		i++;
	}
	if (validate_map(game) == -1)
		return (-1);
	free(lines);
	return (0);
}
