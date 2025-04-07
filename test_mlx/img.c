/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:25:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 18:46:55 by obouhour         ###   ########.fr       */
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

void    init_img(t_game *game)
{
    int width;  // Ajoutez ces variables locales
    int height;

    game->imgs = malloc(sizeof(t_img));
    if (!game->imgs)
    {
        printf("error: Failed to initialize img\n");
        close_window(game);
    }
    game->imgs->NO_img = NULL;
    game->imgs->SO_img = NULL;
    game->imgs->WE_img = NULL;
    game->imgs->EA_img = NULL;

    // Vérifiez les chemins
    if (!game->data || !game->data->NO || !game->data->SO || 
        !game->data->WE || !game->data->EA)
    {
        printf("error: Invalid texture paths\n");
        close_window(game);
    }

    // Afficher les chemins pour debug
    printf("Loading textures from:\nNO: %s\nSO: %s\nWE: %s\nEA: %s\n",
        game->data->NO, game->data->SO, game->data->WE, game->data->EA);

    // Utilisez les variables locales pour width et height
    game->imgs->NO_img = mlx_xpm_file_to_image(game->mlx, game->data->NO, &width, &height);
    game->imgs->SO_img = mlx_xpm_file_to_image(game->mlx, game->data->SO, &width, &height);
    game->imgs->WE_img = mlx_xpm_file_to_image(game->mlx, game->data->WE, &width, &height);
    game->imgs->EA_img = mlx_xpm_file_to_image(game->mlx, game->data->EA, &width, &height);

	printf("test");
    if (!game->imgs->NO_img || !game->imgs->SO_img ||
        !game->imgs->WE_img || !game->imgs->EA_img)
    {
        printf("error: Failed to load one or more textures\n");
        close_window(game);
    }
}
