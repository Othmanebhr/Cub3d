/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:01 by besch             #+#    #+#             */
/*   Updated: 2025/04/15 21:10:57 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	initialize_game(char *map_path, t_game *game)
{
	int		fd;
	char	*cub_tmp;

	if (ft_strlen(map_path) < 4
		|| ft_strncmp(map_path + ft_strlen(map_path) - 4, ".cub", 4) != 0)
		return (ft_error("Error\nInvalid map file extension. Use .cub\n"));
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Error\nFail to opening map file"));
	cub_tmp = read_cub_file(fd, *game);
	if (close(fd) == -1)
		return (ft_error("Error\nFail to closing map file"));
	if (!cub_tmp)
		return (ft_error("Error\nFail to reading map file"));
	if (parse_cub_file(cub_tmp, game) == -1)
	{
		free(cub_tmp);
		return (-1);
	}
}
