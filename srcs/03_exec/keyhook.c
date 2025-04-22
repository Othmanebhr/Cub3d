/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:26:13 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/22 20:28:39 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

void	move_if_no_collision(t_game *game, \
	t_player *player, double next_x, double next_y)
{
	int	map_height;
	int	map_width;
	int	x_dir;
	int	y_dir;

	map_height = game->map.height;
	map_width = game->map.width;
	x_dir = 0;
	if (next_x > player->pos.x)
		x_dir = 1;
	else if (next_x < player->pos.x)
		x_dir = -1;
	y_dir = 0;
	if (next_y > player->pos.y)
		y_dir = 1;
	else if (next_y < player->pos.y)
		y_dir = -1;
	if (next_x >= COLLISION_PADDING && next_x < map_width - COLLISION_PADDING
		&& game->map.grid \
		[(int)player->pos.y][(int)(next_x + COLLISION_PADDING * x_dir)] != '1')
		player->pos.x = next_x;
	if (next_y >= COLLISION_PADDING && next_y < map_height - COLLISION_PADDING
		&& game->map.grid \
		[(int)(next_y + COLLISION_PADDING * y_dir)][(int)player->pos.x] != '1')
		player->pos.y = next_y;
}

/*
formule ; (x, y) vecteur avant rotation et (x', y') post rotation, (θ) pour l'angle
x' = x * cos(θ) - y * sin(θ)
y' = y * sin(θ) + y * cos(θ)
*/

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
