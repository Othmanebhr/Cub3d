/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:33:35 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/05 14:40:36 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MLX_H
#define INIT_MLX_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "../test_extract_data/Extract.h" // Tres certainement a changer post parsing

#define WIDTH 800 // a voir les dimension qu'on veut donner (prendre en compte si sur mac/dell)
#define HEIGHT 700

typedef struct s_img
{
	void	*NO_img;
	void	*So_img;
	void	*WE_img;
	void	*EA_img;
}	t_img;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		dir_x;
	int		dir_y;//a voir tres certainement passer en double/float
	int		plane_x;
	int		plane_y;//meme chose
}	t_player;
/*
plane = positin de la camera qui va etre perpendiculaire a la direction
*/

typedef struct s_game
{
	void			*mlx;
	void			*win;//window
	struct t_img	*imgs;
	struct t_player	*player;
	struct t_data	*data;
}	t_game;

#endif