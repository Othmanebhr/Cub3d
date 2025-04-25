/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse_elements_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:46 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 15:31:36 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static bool	is_valid_rgb_number(const char *s)
{
	int	i;

	i = 0;

	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		return (false);
	if (!ft_isdigit(s[i]))
		return (false);
	while (ft_isdigit(s[i]))
		i++;
	while (s[i] == ' ')
		i++;
	return (s[i] == '\0');
}

static bool	is_rgb_ok(char *str, int *color, t_game *game)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split_gc(str, ',', &game->gc);
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (false);
	if (!is_valid_rgb_number(split[0]) || !is_valid_rgb_number(split[1])
		|| !is_valid_rgb_number(split[2]))
		return (false);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	*color = rgb_to_int(r, g, b);
	return (true);
}

int	handle_color(t_parsing *parsing, t_game *game)
{
	if (ft_strncmp(parsing->tokens[0], "F", 1) == 0)
	{
		if (parsing->found_floor)
			return (ft_error("Error\nDuplicate floor color"));
		parsing->found_floor = true;
		if (is_rgb_ok
			(parsing->tokens[1], &game->map.floor_color, game) == false)
			return (ft_error("Error\nInvalid floor color format"));
	}
	else if (ft_strncmp(parsing->tokens[0], "C", 1) == 0)
	{
		if (parsing->found_ceiling)
			return (ft_error("Error\nDuplicate ceiling color"));
		parsing->found_ceiling = true;
		if (is_rgb_ok
			(parsing->tokens[1], &game->map.ceiling_color, game) == false)
			return (ft_error("Error\nInvalid ceiling color format"));
	}
	return (0);
}
