/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sin_cos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:23:07 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/06 12:40:15 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_cub.h"

int	main(void)
{
	double	i = 45.0;
	double	radian;

	radian = i * PI / 180.0;
	printf("%f\n", cos(radian));
	printf("%f\n", sin(radian));
	return(0);
}

/*pour la lib math ne pas oublier le flag -lm*/

/*
En mathématiques, il existe deux unités principales pour mesurer les angles :

Les degrés (°) : de 0° à 360°
Les radians (rad) : de 0 à 2π

Pourquoi diviser par 180 ?

Un cercle complet fait 360° en degrés
Le même cercle fait 2π en radians
Donc : 180° = π radians

Formule degre en radians:
rad = deg * (PI/180)

*/