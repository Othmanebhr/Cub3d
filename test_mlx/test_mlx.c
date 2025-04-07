/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:08 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 14:40:17 by obouhour         ###   ########.fr       */
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
	{
		printf("error: Failed to initialize game.");
		close_window(game);
	}
}

int	main()
{
	t_game	game;
	
	game.mlx = mlx_init();
	if (!game.mlx)
		return (printf("mlx init error\n"), 1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!game.win)
		return (printf("error: Window\n"), 1);
	init_img(&game);
	check_init(&game);
	init_player(&game);
	mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_keyrelease, &game);
	mlx_loop_hook(game.win, handle_keyhook, &game);
	// mlx_key_hook(game.win, handle_keyhook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);/**/
	mlx_loop(game.mlx);
	return (0);
}


// compile = cc test_mlx.c -L../mlx -lmlx -L/usr/lib -lXext -lX11 -lm
// make la libft et mlx avant
/*

void	*win --> window

mlx_hook(game.win, 17, 0, close_window, &game);
17 = un evenement, ici en l'occurence la mlx le defini le 17 comme la fermeture de la win
0 = Masque (??)

*/