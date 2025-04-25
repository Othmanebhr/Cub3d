/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:04:26 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/25 17:44:37 by besch            ###   ########.fr       */
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

static int	manage_mouse_wrapping(int x, int *prev_x, t_game *game)
{
	int	center_x;
	int	center_y;

	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT / 2;
	if (x < WINDOW_WIDTH / 10 || x > WINDOW_WIDTH * 9 / 10)
	{
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
		*prev_x = center_x;
		return (1);
	}
	return (0);
}

int	mouse_motion(int x, int y, t_game *game)
{
	static int	prev_x = -1;
	static bool	recentered = false;
	int			delta_x;
	double		old_dir_x;
	double		old_plane_x;
	double		rot;

	(void)y;
	if (prev_x == -1)
		prev_x = x;
	if (manage_mouse_wrapping(x, &prev_x, game))
	{
		recentered = true;
		return (0);
	}
	if (recentered)
	{
		recentered = false;
		prev_x = x;
	}
	delta_x = x - prev_x;
	if (delta_x != 0)
	{
		rot = delta_x * 0.003;
		old_dir_x = game->player.dir.x;
		old_plane_x = game->player.plane.x;
		game->player.dir.x = game->player.dir.x * cos(rot) - game->player.dir.y * sin(rot);
		game->player.dir.y = old_dir_x * sin(rot) + game->player.dir.y * cos(rot);
		game->player.plane.x = game->player.plane.x * cos(rot) - game->player.plane.y * sin(rot);
		game->player.plane.y = old_plane_x * sin(rot) + game->player.plane.y * cos(rot);
	}
	prev_x = x;
	return (0);
}
