/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:04:26 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/25 17:06:40 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// mlx_mouse_hide(game->mlx, game->win);

static void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir.x;
	old_plane_x = game->player.plane.x;
	game->player.dir.x = game->player.dir.x * cos(angle) \
		- game->player.dir.y * sin(angle);
	game->player.dir.y = old_dir_x * sin(angle) \
		+ game->player.dir.y * cos(angle);
	game->player.plane.x = game->player.plane.x \
		* cos(angle) - game->player.plane.y * sin(angle);
	game->player.plane.y = old_plane_x * sin(angle) \
		+ game->player.plane.y * cos(angle);
}

int	handle_mouse_move(int x, int y, void *param)
{
	t_game	*game;
	double	sensitivity;
	int		delta_x;
	double	angle;

	(void)y;
	sensitivity = 0.003;
	game = (t_game *)param;
	if (game->img.mouse_last_x == -1)
	{
		game->img.mouse_last_x = x;
		return (0);
	}
	delta_x = x - game->img.mouse_last_x;
	if (delta_x != 0)
	{
		angle = delta_x * sensitivity;
		rotate_player(game, angle);
	}
	game->img.mouse_last_x = x;
	mlx_mouse_move(game->mlx, game->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	game->img.mouse_last_x = WINDOW_WIDTH / 2;
	return (0);
}
