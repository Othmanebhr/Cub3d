/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:18:08 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 18:00:49 by obouhour         ###   ########.fr       */
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

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        return (printf("Usage: ./cub3d map.cub\n"), 1);

    ft_memset(&game, 0, sizeof(t_game));
    
    // Init MLX et window
    game.mlx = mlx_init();
    if (!game.mlx)
        return (printf("MLX init failed\n"), 1);
        
    game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
    if (!game.win)
        return (free(game.mlx), printf("Window creation failed\n"), 1);
    
    // Init keys
    game.keys = malloc(sizeof(t_keys));
    if (!game.keys)
        return (close_window(&game), 1);
    ft_memset(game.keys, 0, sizeof(t_keys));
    
    // Init data pour le parsing
    game.data = malloc(sizeof(t_data));
    if (!game.data)
        return (close_window(&game), 1);

    printf("Starting parsing...\n");
    test_parse(ac, av, game.data);

    printf("Initializing images...\n");
    init_img(&game);
    check_init(&game);
    
    printf("Initializing player...\n");
    init_player(&game);

    // Configurer les hooks
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    mlx_hook(game.win, 3, 1L<<1, handle_keyrelease, &game);
    mlx_loop_hook(game.mlx, handle_keyhook, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);

    // Démarrer la boucle principale
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