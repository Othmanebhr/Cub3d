/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:28:17 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 13:26:02 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

int	close_window(t_game *game)
{
	free_img(game);
	free_player(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		free(game->mlx);
		mlx_destroy_display(game->mlx); // avoir a quoi cela sert
	}
	exit(0);
}
