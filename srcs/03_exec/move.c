/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:19:27 by besch             #+#    #+#             */
/*   Updated: 2025/04/22 20:20:01 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	move_forward(t_game *game, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos.x + player->dir.x * MOVE_SPEED;
	next_y = player->pos.y + player->dir.y * MOVE_SPEED;
	move_if_no_collision(game, player, next_x, next_y);
}

static void	move_backward(t_game *game, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos.x - player->dir.x * MOVE_SPEED;
	next_y = player->pos.y - player->dir.y * MOVE_SPEED;
	move_if_no_collision(game, player, next_x, next_y);
}

static void	move_left(t_game *game, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos.x + player->dir.y * MOVE_SPEED;
	next_y = player->pos.y - player->dir.x * MOVE_SPEED;
	move_if_no_collision(game, player, next_x, next_y);
}

static void	move_right(t_game *game, t_player *player)
{
	double	next_x;
	double	next_y;

	next_x = player->pos.x - player->dir.y * MOVE_SPEED;
	next_y = player->pos.y + player->dir.x * MOVE_SPEED;
	move_if_no_collision(game, player, next_x, next_y);
}

void	handle_move(t_game *game, t_player *player, t_keys *key)
{
	if (key->w)
		move_forward(game, player);
	else if (key->s)
		move_backward(game, player);
	else if (key->a)
		move_left(game, player);
	else if (key->d)
		move_right(game, player);
}
