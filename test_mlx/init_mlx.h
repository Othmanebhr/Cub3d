/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:33:35 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/05 16:19:59 by obouhour         ###   ########.fr       */
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
	void		*NO_img;
	void		*SO_img;
	void		*WE_img;
	void		*EA_img;
}	t_img;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;
/*
plane = positin de la camera qui va etre perpendiculaire a la direction
*/

typedef struct s_game
{
	void		*mlx;
	void		*win;//window
	t_img		*imgs;
	t_player	*player;
	t_data		*data;
}	t_game;

/*Img*/
void	init_img(t_game *game);
void	free_img(t_game *game);

/*Player*/
void	init_player(t_game *game);
void	free_player(t_game *game);

/*Keyhook*/
int		handle_escape(int keycode, t_game *game);

/*Utils*/
int	close_window(t_game *game);

#endif