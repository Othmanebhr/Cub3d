/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:25:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/09 19:49:18 by obouhour         ###   ########.fr       */
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
			mlx_destroy_image(game->mlx, game->imgs->SO_img);
		if (game->imgs->WE_img)
			mlx_destroy_image(game->mlx, game->imgs->WE_img);
		if (game->imgs->EA_img)
			mlx_destroy_image(game->mlx, game->imgs->EA_img);
		free(game->imgs);
	}
}

void init_img(t_game *game)
{
    int width;
    int height;

    game->imgs = malloc(sizeof(t_img));
    if (!game->imgs)
    {
        printf("error: Failed to initialize img\n");
        close_window(game);
    }
    
    // Initialize pointers to NULL
    game->imgs->NO_img = NULL;
    game->imgs->SO_img = NULL;
    game->imgs->WE_img = NULL;
    game->imgs->EA_img = NULL;

    // Check paths
    if (!game->data || !game->data->NO || !game->data->SO || 
        !game->data->WE || !game->data->EA)
    {
        printf("error: Invalid texture paths\n");
        close_window(game);
    }

    // Debug print
    printf("Loading textures from:\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n",
        game->data->NO, game->data->SO, game->data->WE, game->data->EA);

    // Load textures only once
    if (!(game->imgs->NO_img = mlx_xpm_file_to_image(game->mlx, game->data->NO, &width, &height)))
    {
        perror("mlx_xpm_file_to_image failed"); // Ajoutez cette ligne
        printf("error: Failed to load NO texture: %s\n", game->data->NO);
        close_window(game);
    }
    if (!(game->imgs->SO_img = mlx_xpm_file_to_image(game->mlx, game->data->SO, &width, &height)))
    {
        printf("error: Failed to load SO texture: %s\n", game->data->SO);
        close_window(game);
    }
    if (!(game->imgs->WE_img = mlx_xpm_file_to_image(game->mlx, game->data->WE, &width, &height)))
    {
        printf("error: Failed to load WE texture: %s\n", game->data->WE);
        close_window(game);
    }
    if (!(game->imgs->EA_img = mlx_xpm_file_to_image(game->mlx, game->data->EA, &width, &height)))
    {
        printf("error: Failed to load EA texture: %s\n", game->data->EA);
        close_window(game);
    }
}
