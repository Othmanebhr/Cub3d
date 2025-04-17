/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:36:32 by besch             #+#    #+#             */
/*   Updated: 2025/04/17 19:06:27 by besch            ###   ########.fr       */
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
		return (gc_cleanup(&game.gc), 1);
	gc_cleanup(&game.gc);
	write(1, "Map parsed successfully\n", 24);
	return (0);
}
