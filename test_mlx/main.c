/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:28:26 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/12 15:42:42 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

/*
Mettre a jour cette fonction une fois toutes l'init + parse ok
*/
static void	check_init(t_game *game)
{
	if (!game->imgs->EA_img || !game->imgs->NO_img 
		|| !game->imgs->SO_img || !game->imgs->WE_img)
		close_window(game, "error: Failed to initialize game.");
}

static void	init_keys(t_keys *keys)
{
	keys->a = 0;
	keys->w = 0;
	keys->d = 0;
	keys->s = 0;
	keys->left = 0;
	keys->right = 0;
}

static void	init(int ac, char **av, t_game	*game)
{
	test_parse(ac, av, game->data);
	init_img(game);
	check_init(game);
	init_player(game);
	init_keys(game->keys);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (printf("Usage: ./cub3d map.cub\n"), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (printf("MLX init failed\n"), 1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
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
	return (0);
}
