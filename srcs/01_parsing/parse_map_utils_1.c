/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:43 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 16:57:15 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_line_valid(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (is_valid_map_char(line[i]) == false)
			return (false);
	return (true);
}

static bool	is_line_full_of_ones(const char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ')
			return (false);
	return (true);
}

int	check_map_lines(char **lines, int start, int end)
{
	int	i;

	i = start - 1;
	while (++i <= end)
	{
		if (lines[i][0] == '\0')
			return (ft_error("First/last map line must be only 1 and spaces"));
		if (is_line_valid(lines[i]) == false)
			return (ft_error("Error\nInvalid character in map"));
	}
	if (is_line_full_of_ones(lines[start]) == false
		|| is_line_full_of_ones(lines[end]) == false)
		return (ft_error
			("Error\nFirst/last map line must be only 1 and spaces"));
	return (0);
}
