/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Extract.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:38:11 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/15 16:34:42 by obouhour         ###   ########.fr       */
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*ceiling;
	char	*floor;
	int		size_map;
	char	**map;
	char	*save_filename;
	int		map_height;
	int		map_width;
} t_data;

void	test_parse(int ac, char **av, t_data *data);

#endif