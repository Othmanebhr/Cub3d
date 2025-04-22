/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:32:07 by besch             #+#    #+#             */
/*   Updated: 2025/04/22 18:56:51 by besch            ###   ########.fr       */
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

int	close_window(t_game *game)
{
	free_game(game);
	printf("Thanks for playing!\n");
	exit(EXIT_SUCCESS);
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
