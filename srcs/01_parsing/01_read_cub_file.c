/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_read_cub_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:30 by besch             #+#    #+#             */
/*   Updated: 2025/04/26 17:42:40 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static void	ft_strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

// static void	print_cub_tmp(char **cub_tmp)
// {
// 	int	i;

// 	i = -1;
// 	while (cub_tmp && cub_tmp[++i])
// 	{
// 		if (i < 10)
// 			printf("[0%d]: \"%s\"\n", i, cub_tmp[i]);
// 		else
// 			printf("[%d]: \"%s\"\n", i, cub_tmp[i]);
// 	}
// }

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

// print_cub_tmp(lines);