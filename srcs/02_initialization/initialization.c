/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:01 by besch             #+#    #+#             */
/*   Updated: 2025/04/21 21:06:42 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_cub_file(char **cub_tmp, t_game *game)
{
	if (verify_elements(cub_tmp, game) == 1)
		return (1);
	if (parse_map(cub_tmp, game) == 1)
		return (1);
	return (0);
}

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("MLX init failed\n"));
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
		return (ft_error("Window creation failed\n"));
	return (0);
}

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
	if (parse_cub_file(cub_tmp, game) == 1)
		return (1);
	if (init_mlx(game) == 1)
		return (1);
	return (0);
}
