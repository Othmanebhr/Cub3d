/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:08:01 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/26 17:31:57 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
Formules : calcul du pas et de la distance initiale jusqu'à la première
intersection de grille (noms génériques)

Pour l'axe X :
Si la direction du rayon sur X est négative :
	pas_sur_X = -1
	distance_premiere_grille_X = (position_joueur_X - case_grille_X) * 
	longueur_case_X
Sinon :
	pas_sur_X = 1
	distance_premiere_grille_X = (case_grille_X + 1.0 - position_joueur_X) 
	* longueur_case_X

Pour l'axe Y :
Si la direction du rayon sur Y est négative :
	pas_sur_Y = -1
	distance_premiere_grille_Y = (position_joueur_Y - case_grille_Y) * 
	longueur_case_Y
Sinon :
	pas_sur_Y = 1
	distance_premiere_grille_Y = (case_grille_Y + 1.0 - position_joueur_Y) * 
	longueur_case_Y
*/
static void	calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (ray->map_x + 1.0 - player->pos.x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (ray->map_y + 1.0 - player->pos.y) * ray->delta_dist_y;
	}
}

/*
Recupere la dist entre le player et le mur
Formules : calcul de la hauteur de la ligne et des bornes de dessin
hauteur_ligne = hauteur_fenetre / distance
debut_dessin = -hauteur_ligne / 2 + hauteur_fenetre / 2
fin_dessin = hauteur_ligne / 2 + hauteur_fenetre / 2
*/
static void	calculate_wall_distance(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist
			= (ray->map_x - player->pos.x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist
			= (ray->map_y - player->pos.y + (1 - ray->step_y) / 2) / ray->dir_y;
}


void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;
	int		color;
	int		line_height;

	x = 0;
	color = 0;
	line_height = 0;
	color_handle(game);
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step_and_side_dist(&ray, &game->player);
		perform_dda(&ray, &game->map);
		calculate_wall_distance(&ray, &game->player);
		draw_wall(game, &ray, x, color, line_height);
		x++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
