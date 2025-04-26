/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:04:26 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/26 17:25:29 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static int	should_recenter_mouse(int x)
{
	if (x < WIN_WIDTH / 10 || x > WIN_WIDTH * 9 / 10)
		return (1);
	return (0);
}

static int	is_first_mouse_event(int *prev_x, int x)
{
	if (*prev_x == -1)
	{
		*prev_x = x;
		return (1);
	}
	return (0);
}

static int	handle_recentered(int *recentered, int *prev_x, int x)
{
	if (*recentered)
	{
		*recentered = 0;
		*prev_x = x;
		return (1);
	}
	return (0);
}

int	mouse_motion(int x, int y, t_game *game)
{
	static int	prev_x = -1;
	static int	recentered = 0;
	int			delta_x;
	double		rot;

	(void)y;
	if (is_first_mouse_event(&prev_x, x))
		return (0);
	if (should_recenter_mouse(x))
	{
		mlx_mouse_move(game->mlx, game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
		prev_x = WIN_WIDTH / 2;
		recentered = 1;
		return (0);
	}
	if (handle_recentered(&recentered, &prev_x, x))
		return (0);
	delta_x = x - prev_x;
	if (delta_x != 0)
	{
		rot = delta_x * 0.003;
		rotate_player(game, rot);
	}
	prev_x = x;
	return (0);
}
