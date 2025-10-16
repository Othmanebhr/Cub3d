/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:37:03 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/26 17:33:49 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
Formule : distance projetée sur la caméra
Si côté touché vertical :
distance = (carte_x - pos_x + (1 - pas_x) / 2) / dir_x
Sinon :
distance = (carte_y - pos_y + (1 - pas_y) / 2) / dir_y
/////

Formules : calcul du rayon pour chaque colonne de l'écran

Coordonnée caméra (de -1 à 1) :
camera_x = 2 * col_x / WINDOW_WIDTH - 1

Direction du rayon :
dir_x = dir_joueur_x + plan_camera_x * camera_x
dir_y = dir_joueur_y + plan_camera_y * camera_x
*/

void	init_ray(t_ray *ray, t_player *player, int col_x)
{
	ray->camera_x = 2 * col_x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir.x + player->plane.x * ray->camera_x;
	ray->dir_y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}
