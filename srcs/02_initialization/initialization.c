/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:01 by besch             #+#    #+#             */
/*   Updated: 2025/04/18 19:48:21 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Fonction principale
int	parse_cub_file(char *cub_tmp, t_game *game)
{
	char	**lines;

	lines = ft_split_gc(cub_tmp, '\n', &game->gc);
	if (!lines)
		return (ft_error("Error\nFail to split cub file"));
	if (verify_elements(lines, game) == 1)
		return (1);
	if (parse_map(lines, game) == 1)
		return (1);
	return (0);
}

char	*read_cub_file(int fd, t_game *game)
{
	char	*line;
	char	*content;

	content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		content = ft_strjoin_gc(content, line, &game->gc);
		free(line);
	}
	return (content);
}

int	initialize_game(char *cub_path, t_game *game)
{
	int		fd;
	char	*cub_tmp;

	if (ft_strlen(cub_path) < 5
		|| ft_strncmp(cub_path + ft_strlen(cub_path) - 4, ".cub", 4) != 0)
		return (ft_error("Error\nInvalid map file extension. Use .cub"));
	fd = open(cub_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Error\nFail to opening map file"));
	cub_tmp = read_cub_file(fd, game);
	if (close(fd) == -1)
		return (ft_error("Error\nFail to closing map file"));
	if (!cub_tmp)
		return (ft_error("Error\nFail to reading map file"));
	if (parse_cub_file(cub_tmp, game) == 1)
		return (1);
	return (0);
}
