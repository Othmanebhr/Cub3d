/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/11 11:52:57 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game, "Thanks for playing!");
	else if (keycode == 119)
		game->keys->w = 1;
	else if (keycode == 115)
		game->keys->s = 1;
	else if (keycode == 97)
		game->keys->a = 1;
	else if (keycode == 100)
		game->keys->d = 1;
	else if (keycode == 65361)
		game->keys->left = 1;
	else if (keycode == 65363)
		game->keys->right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 119)
		game->keys->w = 0;
	else if (keycode == 115)
		game->keys->s = 0;
	else if (keycode == 97)
		game->keys->a = 0;
	else if (keycode == 100)
		game->keys->d = 0;
	else if (keycode == 65361)
		game->keys->left = 0;
	else if (keycode == 65363)
		game->keys->right = 0;
	return (0);
}

static void	handle_move(t_player *player, t_keys *key)
{
	if (key->w)
	{
		player->pos_x += player->dir_x * MOVE_SPD;
		player->pos_y += player->dir_y * MOVE_SPD;
	}
	else if (key->s)
	{
		player->pos_x -= player->dir_x * MOVE_SPD;
		player->pos_y -= player->dir_y * MOVE_SPD;
	}
	else if (key->a)
	{
		player->pos_x += player->dir_y * MOVE_SPD;
		player->pos_y -= player->dir_x * MOVE_SPD;
	}
	else if (key->d)
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
static void	handle_rotation(t_player *player, t_keys *key)
{
	double	save_dir_x;
	double	save_plane_x;

	if (key->left)
	{
		save_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPD) - player->dir_y * sin(ROT_SPD);
		player->dir_y = save_dir_x * sin(ROT_SPD) + player->dir_y * cos(ROT_SPD);
		save_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(ROT_SPD) - player->plane_y * sin(ROT_SPD);
		player->plane_y = save_plane_x * sin(ROT_SPD) + player->plane_y * cos(ROT_SPD);
	}
	else if (key->right)
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
		close_window(game, "Thanks for playing!");//exit value a changer potentiellement
	if (game->keys->a || game->keys->d || game->keys->s || game->keys->w)
		handle_move(game->player, game->keys);
	if (game->keys->left || game->keys->right)
		handle_rotation(game->player, game->keys);
	return (0);
}
