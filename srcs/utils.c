/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:32:07 by besch             #+#    #+#             */
/*   Updated: 2025/04/21 21:08:07 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

static void	free_img(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->textures)
	{
		if (game->textures[NORTH].img)
			mlx_destroy_image(game->mlx, game->textures[NORTH].img);
		if (game->textures[SOUTH].img)
			mlx_destroy_image(game->mlx, game->textures[SOUTH].img);
		if (game->textures[WEST].img)
			mlx_destroy_image(game->mlx, game->textures[WEST].img);
		if (game->textures[EAST].img)
			mlx_destroy_image(game->mlx, game->textures[EAST].img);
	}
}

int	free_game(t_game *game)
{
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free_img(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	gc_cleanup(&game->gc);
	return (0);
}

int	close_window(t_game *game, char *str)
{
	printf("%s\n",str);
	if (!game)
		exit(EXIT_FAILURE);
	free_img(game);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	gc_cleanup(&game->gc);
	exit(0);
}
