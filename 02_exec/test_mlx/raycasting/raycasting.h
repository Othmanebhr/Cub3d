/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:54:08 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/15 16:47:26 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "../init_mlx.h"

struct s_game;
struct s_player;

typedef struct s_ray
{
	double	camera_x; //coordonee x dans l'espace camera (?)
	double	dir_x; //dir x du rayon
	double	dir_y; //dir y du rayon
	int		map_x; //position x sur la carte
	int		map_y; //postions y sur la carte
	double	side_dist_x; //distance depuis la position actuelle jusqu'au prochain cote y
	double	side_dist_y; //distance depuis la positions actuelle jusqu'au prochain cote x
	double	delta_dist_x; //distance entre deux cote x consecutif
	double	delta_dist_y; //meme chose pour y
	int		step_x; //direction du pas en x (-1 ou 1)
	int		step_y; //same en y
	int		hit; //1 si mur a ete touche, 0 si non
	int		side; // 0 si un cote x a ete touche, 1 si un cote y a ete touche
	double	perp_wall_dist; //distance perpendiculaire du joueur au mur
}	t_ray;

//raycasting
void	raycasting(t_game	*game);

//init struct 
void	init_ray(t_ray *ray, t_player *player, int x);

#endif