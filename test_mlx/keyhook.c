/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/21 13:49:34 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"
#include "raycasting/raycasting.h"

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
static void	move_if_no_collision(t_game *game, t_player *player, double next_x, double next_y)
{
	int map_height = game->data->map_height;
	int map_width = game->data->map_width;

	// Vérifie les limites avant d'accéder à la map
	if (next_x >= 0 && next_x < map_width &&
		player->pos_y >= 0 && player->pos_y < map_height &&
		game->data->map[(int)player->pos_y][(int)next_x] != '1')
		player->pos_x = next_x;
	if (next_y >= 0 && next_y < map_height &&
		player->pos_x >= 0 && player->pos_x < map_width &&
		game->data->map[(int)next_y][(int)player->pos_x] != '1')
		player->pos_y = next_y;
}

static void	handle_move(t_game *game, t_player *player, t_keys *key)
{
	double	next_x;
	double	next_y;

	next_x = 0.0;
	next_y = 0.0;
	if (key->w)
	{
		next_x = player->pos_x + player->dir_x * MOVE_SPD;
		next_y = player->pos_y + player->dir_y * MOVE_SPD;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->s)
	{
		next_x = player->pos_x - player->dir_x * MOVE_SPD;
		next_y = player->pos_y - player->dir_y * MOVE_SPD;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->a)
	{
		next_x = player->pos_x + player->dir_y * MOVE_SPD;
		next_y = player->pos_y - player->dir_x * MOVE_SPD;
		move_if_no_collision(game, player, next_x, next_y);
	}
	else if (key->d)
	{
		next_x = player->pos_x - player->dir_y * MOVE_SPD;
		next_y = player->pos_y + player->dir_x * MOVE_SPD;
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

int	handle_keyhook(t_game *game)
{
	if (!game->keys && !game->player)
	{
		printf("test\n");
		exit(1);
	}
	if (game->keys->a || game->keys->d || game->keys->s || game->keys->w)
		handle_move(game, game->player, game->keys);
	if (game->keys->left || game->keys->right)
		handle_rotation(game->player, game->keys);
	mlx_clear_window(game->mlx, game->win);
	raycasting(game);
	return (0);
}
