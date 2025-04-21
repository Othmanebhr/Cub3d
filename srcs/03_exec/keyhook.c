/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/21 20:37:00 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_window(game, "Thanks for playing!");
	else if (keycode == 119)
		game->keys.w = 1;
	else if (keycode == 115)
		game->keys.s = 1;
	else if (keycode == 97)
		game->keys.a = 1;
	else if (keycode == 100)
		game->keys.d = 1;
	else if (keycode == 65361)
		game->keys.left = 1;
	else if (keycode == 65363)
		game->keys.right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 119)
		game->keys.w = 0;
	else if (keycode == 115)
		game->keys.s = 0;
	else if (keycode == 97)
		game->keys.a = 0;
	else if (keycode == 100)
		game->keys.d = 0;
	else if (keycode == 65361)
		game->keys.left = 0;
	else if (keycode == 65363)
		game->keys.right = 0;
	return (0);
}

static void	move_if_no_collision(t_game *game, t_player *player, double next_x, double next_y)
{
	int	map_height = game->map.height;
	int	map_width = game->map.width;

	// Collision sur X
	if (next_x >= 0 && next_x < map_width &&
		player->pos.y >= 0 && player->pos.y < map_height &&
		game->map.grid[(int)player->pos.y][(int)next_x] != '1')
		player->pos.x = next_x;

	// Collision sur Y
	if (next_y >= 0 && next_y < map_height &&
		player->pos.x >= 0 && player->pos.x < map_width &&
		game->map.grid[(int)next_y][(int)player->pos.x] != '1')
		player->pos.y = next_y;
}

static void	handle_move(t_game *game, t_player *player, t_keys *key)
{
	double	next_x;
	double	next_y;

	next_x = 0.0;
	next_y = 0.0;
	if (key->w)
	{
		next_x = player->pos.x + player->dir.x * MOVE_SPEED;
		next_y = player->pos.y + player->dir.y * MOVE_SPEED;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->s)
	{
		next_x = player->pos.x - player->dir.x * MOVE_SPEED;
		next_y = player->pos.y - player->dir.y * MOVE_SPEED;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->a)
	{
		next_x = player->pos.x + player->dir.y * MOVE_SPEED;
		next_y = player->pos.y - player->dir.x * MOVE_SPEED;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->d)
	{
		next_x = player->pos.x - player->dir.y * MOVE_SPEED;
		next_y = player->pos.y + player->dir.x * MOVE_SPEED;
		move_if_no_collision(game, player, next_x, next_y);
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

	if (key->right)
	{
		save_dir_x = player->dir.x;
		player->dir.x
			= player->dir.x * cos(ROT_SPEED) - player->dir.y * sin(ROT_SPEED);
		player->dir.y
			= save_dir_x * sin(ROT_SPEED) + player->dir.y * cos(ROT_SPEED);
		save_plane_x = player->plane.x;
		player->plane.x
			= player->plane.x * cos(ROT_SPEED) - player->plane.y * sin(ROT_SPEED);
		player->plane.y
			= save_plane_x * sin(ROT_SPEED) + player->plane.y * cos(ROT_SPEED);
	}
	else if (key->left)
	{
		save_dir_x = player->dir.x;
		player->dir.x
			= player->dir.x * cos(-ROT_SPEED) - player->dir.y * sin(-ROT_SPEED);
		player->dir.y
			= save_dir_x * sin(-ROT_SPEED) + player->dir.y * cos(-ROT_SPEED);
		save_plane_x = player->plane.x;
		player->plane.x
			= player->plane.x * cos(-ROT_SPEED) - player->plane.y * sin(-ROT_SPEED);
		player->plane.y
			= save_plane_x * sin(-ROT_SPEED) + player->plane.y * cos(-ROT_SPEED);
	}
}

int	handle_keyhook(t_game *game)
{
	if (game->keys.a || game->keys.d || game->keys.s || game->keys.w)
		handle_move(game, &game->player, &game->keys);
	if (game->keys.left || game->keys.right)
		handle_rotation(&game->player, &game->keys);
	mlx_clear_window(game->mlx, game->win);
	raycasting(game);
	return (0);
}
