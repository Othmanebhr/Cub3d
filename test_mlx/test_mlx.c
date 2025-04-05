/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:08 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/05 12:37:08 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (1);
}

int	handle_escape(int keycode, t_game *game)
{
	printf("Touche pressée: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (1);
}

int main()
{
	t_game	game;
	
	game.mlx = mlx_init();
	if (!game.mlx)
		return (printf("mlx init error\n"), 1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!game.win)
		return (printf("error: Window\n"), 1);
	mlx_key_hook(game.win, handle_escape, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);/**/
	mlx_loop(game.mlx);
	return (0);
}


// compile = cc test_mlx.c -L../mlx -lmlx -L/usr/lib -lXext -lX11 -lm

/*

void	*win --> window

mlx_hook(game.win, 17, 0, close_window, &game);
17 = un evenement, ici en l'occurence la mlx le defini le 17 comme la fermeture de la win
0 = Masque (??)

*/