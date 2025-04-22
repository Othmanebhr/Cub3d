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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("Error\nCorrect usage: ./cub3D <map.cub>\n"));
	ft_memset(&game, 0, sizeof(t_game));
	if (initialize_game(av[1], &game) == 1)
		return (free_game(&game), 1);
	mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L<<1, handle_keyrelease, &game);
	mlx_loop_hook(game.mlx, handle_keyhook, &game);
	mlx_hook(game.win, 17, 0, free_game, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
