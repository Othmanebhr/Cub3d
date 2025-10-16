/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:24:06 by besch             #+#    #+#             */
/*   Updated: 2025/04/22 20:24:18 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	rotate_right(t_player *player)
{
	double	save_dir_x;
	double	save_plane_x;

	save_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(ROT_SPEED)
		- player->dir.y * sin(ROT_SPEED);
	player->dir.y = save_dir_x * sin(ROT_SPEED)
		+ player->dir.y * cos(ROT_SPEED);
	save_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(ROT_SPEED)
		- player->plane.y * sin(ROT_SPEED);
	player->plane.y = save_plane_x * sin(ROT_SPEED)
		+ player->plane.y * cos(ROT_SPEED);
}

static void	rotate_left(t_player *player)
{
	double	save_dir_x;
	double	save_plane_x;

	save_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-ROT_SPEED)
		- player->dir.y * sin(-ROT_SPEED);
	player->dir.y = save_dir_x * sin(-ROT_SPEED)
		+ player->dir.y * cos(-ROT_SPEED);
	save_plane_x = player->plane.x;
	player->plane.x = player->plane.x * cos(-ROT_SPEED)
		- player->plane.y * sin(-ROT_SPEED);
	player->plane.y = save_plane_x * sin(-ROT_SPEED)
		+ player->plane.y * cos(-ROT_SPEED);
}

void	handle_rotation(t_player *player, t_keys *key)
{
	if (key->right)
		rotate_right(player);
	else if (key->left)
		rotate_left(player);
}
