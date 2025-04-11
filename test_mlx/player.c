/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:03:12 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/11 11:57:44 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	free_player(t_game *game)
{
	if (game->player)
		free(game->player);
	game->player = NULL;
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	close_window(game, "error: Failed to malloc player's struct");
	game->player->pos_x = WIDTH / 2; //La position post parsing changera mais pour l'instant je le mets au millieu de la map
	game->player->pos_y = HEIGHT / 2;
	game->player->dir_x = 1.0; //regarde l'est par default pour l'instant
	game->player->dir_y = 0.0;
	game->player->plane_x = 0.0;
	game->player->plane_y = 0.66;//a revoir mais poour avoir une fov d'environ 66 degres
}
