/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 13:04:13 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

static void	handle_move(t_player *player, int keycode)
{
	if (keycode == 119)//w
	{
		player->pos_x += player->dir_x * MOVE_SPD;
		player->pos_y += player->dir_y * MOVE_SPD;
	}
	if (keycode == 115)//s
	{
		player->pos_x -= player->dir_x * MOVE_SPD;
		player->pos_y -= player->dir_y * MOVE_SPD;
	}
}
/*
formule ; (x, y) vecteur avant rotation et (x', y') post rotation, (θ) pour l'angle
x' = x * cos(θ) - y * sin(θ)
y' = y * sin(θ) + y * cos(θ)
*/
static void	handle_rotation(t_player *player, int keycode)
{
	double	save_dir_x;
	double	save_plane_x;
	if (keycode == 65361)//f/gauche
	{
		save_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPD) - player->dir_y * sin(ROT_SPD);
		player->dir_y = save_dir_x * sin(ROT_SPD) + player->dir_y * cos(ROT_SPD);
		save_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPD) - player->plane_y * sin(ROT_SPD);
		player->plane_y = save_plane_x * sin(ROT_SPD) + player->plane_y * cos(ROT_SPD);
	}
	if (keycode == 65363)//f/droite
	{
		save_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPD) - player->dir_y * sin(-ROT_SPD);
		player->dir_y = save_dir_x * sin(-ROT_SPD) + player->dir_y * cos(-ROT_SPD);
		save_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPD) + player->plane_y * sin(-ROT_SPD);
		player->plane_y = save_dir_x * sin(-ROT_SPD) + player->plane_y * cos(-ROT_SPD);
	}
}

int	handle_keyhook(int keycode, t_game *game)
{
	if (keycode == 65307)//echap
		close_window(game);
	handle_move(game->player, keycode);
	handle_rotation(game->player, keycode);
	return (0);
}
