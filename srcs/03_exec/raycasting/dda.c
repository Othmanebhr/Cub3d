/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:39:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/26 17:33:34 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	perform_dda(t_ray *ray, t_map *map)
{
	// Algorithme DDA pour trouver le point d'intersection avec un mur
	while (ray->hit == 0)
	{
		// Sauter au prochain carré de la carte
		if (ray->side_dist_x < ray->side_dist_y)
		{
			// Avancer dans la direction X
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0; // Touché un côté vertical (Est/Ouest)
		}
		else
		{
			// Avancer dans la direction Y
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1; // Touché un côté horizontal (Nord/Sud)
		}
		// Vérifier si le rayon a touché un mur
		// Assurez-vous que map_x et map_y sont dans les limites de la carte
		if (ray->map_y < 0 || ray->map_x < 0
			|| ray->map_y >= map->height || ray->map_x >= map->width
			|| map->grid[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1; // Un mur est touché
		}
	}
}
