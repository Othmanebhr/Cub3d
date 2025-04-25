/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:01 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 16:03:13 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	load_texture(t_game *game, int dir)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->textures[dir].img
		= mlx_xpm_file_to_image(game->mlx, game->textures[dir].path, &w, &h);
	if (!game->textures[dir].img)
	{
		ft_error("Error\nFailed to load");
		if (dir == NORTH)
			return (ft_error(" NO texture"));
		else if (dir == SOUTH)
			return (ft_error(" SO texture"));
		else if (dir == WEST)
			return (ft_error(" WE texture"));
		else if (dir == EAST)
			return (ft_error(" EA texture"));
	}
	game->textures[dir].addr = mlx_get_data_addr(game->textures[dir].img, \
		&game->textures[dir].bits_per_pixel, &game->textures[dir].line_len, \
		&game->textures[dir].endian);
	game->textures[dir].width = w;
	game->textures[dir].height = h;
	return (0);
}

static int	init_frame_buffer(t_game *game)
{
	int	w;
	int	h;

	w = WINDOW_WIDTH;
	h = WINDOW_HEIGHT;
	game->img.img = mlx_new_image(game->mlx, w, h);
	if (!game->img.img)
		return (ft_error("Error\nFailed to create frame buffer"));
	game->img.addr = mlx_get_data_addr(game->img.img, \
									&game->img.bits_per_pixel, \
									&game->img.line_len, \
									&game->img.endian);
	game->img.width = w;
	game->img.height = h;
	return (0);
}

static int	init_mlx_and_imgs(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Error\nMLX init failed\n"));
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
		return (ft_error("Error\nWindow creation failed\n"));
	if (load_texture(game, NORTH) || load_texture(game, SOUTH)
		|| load_texture(game, WEST) || load_texture(game, EAST)
		|| init_frame_buffer(game))
		return (1);
	return (0);
}

static int	parse_cub_file(char **cub_tmp, t_game *game)
{
	if (verify_elements(cub_tmp, game) == 1)
		return (1);
	if (parse_map(cub_tmp, game) == 1)
		return (1);
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
		return (gc_cleanup(&game->gc), \
		ft_error("Error\nFail to closing map file"));
	if (!cub_tmp)
		return (gc_cleanup(&game->gc), \
		ft_error("Error\nFail to reading map file"));
	if (parse_cub_file(cub_tmp, game) == 1)
		return (gc_cleanup(&game->gc), 1);
	if (init_mlx_and_imgs(game) == 1)
		return (gc_cleanup(&game->gc), 1);
	return (0);
}
