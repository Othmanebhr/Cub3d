/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 13:09:38 by obouhour         ###   ########.fr       */
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
	else if (keycode == 115)//s
	{
		player->pos_x -= player->dir_x * MOVE_SPD;
		player->pos_y -= player->dir_y * MOVE_SPD;
	}
	else if (keycode == 97)//a
	{
		player->pos_x += player->dir_y * MOVE_SPD;
		player->pos_y -= player->dir_x * MOVE_SPD;
	}
	else if (keycode == 100)//d
	{
		player->pos_x -= player->dir_y * MOVE_SPD;
		player->pos_y += player->dir_x * MOVE_SPD;
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

	if (keycode == 65361)//f.gauche
	{
		save_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPD) - player->dir_y * sin(ROT_SPD);
		player->dir_y = save_dir_x * sin(ROT_SPD) + player->dir_y * cos(ROT_SPD);
		save_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPD) - player->plane_y * sin(ROT_SPD);
		player->plane_y = save_plane_x * sin(ROT_SPD) + player->plane_y * cos(ROT_SPD);
	}
	else if (keycode == 65363)//f.droite
	{
		save_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPD) - player->dir_y * sin(-ROT_SPD);
		player->dir_y = save_dir_x * sin(-ROT_SPD) + player->dir_y * cos(-ROT_SPD);
		save_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-ROT_SPD) + player->plane_y * sin(-ROT_SPD);
		player->plane_y = save_dir_x * sin(-ROT_SPD) + player->plane_y * cos(-ROT_SPD);
	}
}

int	handle_keyhook(int kc, t_game *game)
{
	if (kc == 65307)//echap
		close_window(game);
	if (kc == 119 || kc == 115 || kc == 97 || kc == 100)
		handle_move(game->player, kc);
	if (kc == 65361 || kc == 65363)
		handle_rotation(game->player, kc);
	return (0);
}
