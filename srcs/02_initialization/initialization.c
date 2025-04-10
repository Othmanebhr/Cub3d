/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:01 by besch             #+#    #+#             */
/*   Updated: 2025/04/10 20:06:04 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	initialize_game(t_game *game, char *map_path)
{
	int	fd;

	if (ft_strlen(map_path) < 4 || ft_strncmp(map_path + ft_strlen(map_path) - 4, ".cub", 4) != 0)
		return (ft_error("Error\nInvalid map file extension. Use .cub\n"));
	game->map_path = ft_strdup(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening map file");
		return (-1);
	}
	if (parse_map(game, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	if (load_textures(game) == -1)
	{
		close(fd);
		return (-1);
	}
	if (setup_mlx(game) == -1)
	{
		close(fd);
		return (-1);
	}
}
