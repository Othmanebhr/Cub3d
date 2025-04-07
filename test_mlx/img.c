/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:25:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 14:35:19 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	free_img(t_game *game)
{
	if (game->imgs)
	{
		if (game->imgs->NO_img)
			mlx_destroy_image(game->mlx, game->imgs->NO_img);
		if (game->imgs->SO_img)
			mlx_destroy_image(game->mlx, game->imgs->NO_img);
		if (game->imgs->WE_img)
			mlx_destroy_image(game->mlx, game->imgs->WE_img);
		if (game->imgs->EA_img)
			mlx_destroy_image(game->mlx, game->imgs->EA_img);
		free(game->imgs);
	}
}

void	init_img(t_game *game)
{
	game->imgs = malloc(sizeof(t_img));
	if (!game->imgs)
	{
		printf("error: Failed to initialize img\n");
		exit(EXIT_FAILURE);
	}
	game->imgs->NO_img = NULL;
	game->imgs->SO_img = NULL;
	game->imgs->WE_img = NULL;
	game->imgs->EA_img = NULL;
	game->imgs->NO_img = mlx_xpm_file_to_image(game->mlx, game->data->NO, (int *)WIDTH, (int *)HEIGHT);
	game->imgs->SO_img = mlx_xpm_file_to_image(game->mlx, game->data->SO, (int *)WIDTH, (int *)HEIGHT);
	game->imgs->WE_img = mlx_xpm_file_to_image(game->mlx, game->data->WE, (int *)WIDTH, (int *)HEIGHT);
	game->imgs->EA_img = mlx_xpm_file_to_image(game->mlx, game->data->EA, (int *)WIDTH, (int *)HEIGHT);
	if (!game->imgs->NO_img || !game->imgs->SO_img ||
		!game->imgs->WE_img || !game->imgs->EA_img)
	{
		printf("error: Failed to initialize img\n");
		close_window(game);
	}
}
