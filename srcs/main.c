/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:36:32 by besch             #+#    #+#             */
/*   Updated: 2025/04/21 20:53:30 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_init(t_game *game)
{
	if (!game->imgs->EA_img || !game->imgs->NO_img
		|| !game->imgs->SO_img || !game->imgs->WE_img)
		close_window(game, "error: Failed to initialize game.");
}

static void	init(int ac, char **av, t_game	*game)
{
	init_img(game);
	check_init(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Usage: ./cub3d map.cub\n"), 1);
	
	init(ac, av, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, handle_keyhook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("Error\nCorrect usage: ./cub3D <map.cub>\n"));
	ft_memset(&game, 0, sizeof(t_game));
	if (initialize_game(av[1], &game) == 1)
		return (free_game(&game), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (printf("MLX init failed\n"), 1);
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game.win)
		return (free(game.mlx), printf("Window creation failed\n"), 1);
	game.keys = malloc(sizeof(t_keys));
	if (!game.keys)
		return (close_window(&game, "error: Failed to init Keys"), 1);
	game.data = malloc(sizeof(t_data));//A enlever post parsing
	if (!game.data)
		return (close_window(&game, "error: Failed to init data"), 1);
	init(ac, av, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, handle_keyhook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
