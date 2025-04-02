/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extract.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:38:11 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/02 17:05:10 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_H
#define EXTRACT_H

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_data
{
	int		fd;
	int		size;
	char	**tab;
} t_data;

#endif