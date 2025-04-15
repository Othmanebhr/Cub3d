/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:36:32 by besch             #+#    #+#             */
/*   Updated: 2025/04/15 20:36:12 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("Error\nCorrect usage: ./cub3D <map.cub>\n"));
	ft_memset(&game, 0, sizeof(t_game));
	if (initialize_game(av[1], &game) == -1)
		return (-1);
}
