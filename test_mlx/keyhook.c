/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/06 15:40:16 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

int	handle_keyhook(int keycode, t_game *game)
{
	double	old_dir;
	double	old_plane;

	if (keycode == 65307)//echap
		close_window(game);
	if (keycode == 65363) //f/droite
	{

	}
	if (keycode == 65361) //f/gauche
	{

	}
	if (keycode == 119)//w
	{
		game->player->pos_x += game->player->dir_x + MOVE_SPD;
		game->player->pos_y += game->player->dir_y + MOVE_SPD;
	}
	if (keycode == 115)//s
	{
		game->player->pos_x -= game->player->dir_x + MOVE_SPD;
		game->player->pos_y -= game->player->dir_y + MOVE_SPD;
	}
	return (1);
}
