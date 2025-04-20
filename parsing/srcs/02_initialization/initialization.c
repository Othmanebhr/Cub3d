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
int	parse_cub_file(char **cub_tmp, t_game *game)
{
	if (verify_elements(cub_tmp, game) == 1)
		return (1);
	if (parse_map(cub_tmp, game) == 1)
		return (1);
	return (0);
}

char	**resize_lines(char **lines, size_t new_cap, size_t count, t_game *game)
{
	char	**tmp;
	size_t	i;

	tmp = gc_malloc(sizeof(char *) * new_cap, &game->gc);
	i = -1;
	while (++i < count)
		tmp[i] = lines[i];
	return (tmp);
}

void	ft_strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

char	**read_cub_file(int fd, t_game *game)
{
	char	*line;
	char	**lines;
	size_t	count;
	size_t	cap;

	count = 0;
	cap = 64;
	lines = gc_malloc(sizeof(char *) * cap, &game->gc);
	line = get_next_line(fd);
	while (line)
	{
		ft_strip_newline(line);
		if (count + 1 >= cap)
		{
			cap *= 2;
			lines = resize_lines(lines, cap, count, game);
		}
		lines[count++] = gc_malloc(ft_strlen(line) + 1, &game->gc);
		ft_strlcpy(lines[count - 1], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(fd);
	}
	lines[count] = NULL;
	return (lines);
}

// static void	print_cub_tmp(char **cub_tmp)
// {
// 	int	i;

// 	i = -1;
// 	while (cub_tmp && cub_tmp[++i])
// 		printf("[%d]: \"%s\"\n", i, cub_tmp[i]);
// }

int	initialize_game(char *cub_path, t_game *game)
{
	int		fd;
	char	**cub_tmp;

	if (ft_strlen(cub_path) < 5
		|| ft_strncmp(cub_path + ft_strlen(cub_path) - 4, ".cub", 4) != 0)
		return (ft_error("Error\nInvalid map file extension. Use myfile.cub"));
	fd = open(cub_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Error\nFail to opening map file"));
	cub_tmp = read_cub_file(fd, game);
	if (close(fd) == -1)
		return (ft_error("Error\nFail to closing map file"));
	if (!cub_tmp)
		return (ft_error("Error\nFail to reading map file"));
	// print_cub_tmp(cub_tmp);
	if (parse_cub_file(cub_tmp, game) == 1)
		return (1);
	return (0);
}
