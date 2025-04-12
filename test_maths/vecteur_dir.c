/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:39:38 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/06 12:49:42 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_cub.h"

/*Exos de rotations de 90deg*/
int main(void)
{
	double old_x = 1.0;
	double old_y = 0.0;
	double new_x = 0.0;
	double new_y = 0.0;

	/*angle de 90deg donc en radians c'est PI/2*/
	new_x = old_x * cos(PI / 2) - old_y * sin(PI / 2);
	new_y = old_x * sin(PI /2) + old_y * cos(PI / 2);
	printf("New pos = (%f,%f)\n", new_x, new_y);
}