/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:48 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 15:30:12 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_map_line(const char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (false);
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '0' && line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static int	dispatch_element(t_parsing *parsing, t_game *game)
{
	if (ft_strcmp(parsing->tokens[0], "NO") == 0)
		return (handle_texture(parsing, game, 0));
	else if (ft_strcmp(parsing->tokens[0], "SO") == 0)
		return (handle_texture(parsing, game, 1));
	else if (ft_strcmp(parsing->tokens[0], "WE") == 0)
		return (handle_texture(parsing, game, 2));
	else if (ft_strcmp(parsing->tokens[0], "EA") == 0)
		return (handle_texture(parsing, game, 3));
	else if (ft_strcmp(parsing->tokens[0], "F") == 0
		|| ft_strcmp(parsing->tokens[0], "C") == 0)
		return (handle_color(parsing, game));
	else
		return (ft_error("Error\nUnknown identifier"));
}

static bool	is_line_empty(const char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (true);
	while (line[++i])
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\0' && line[i] != '\n')
			return (false);
	return (true);
}

int	verify_elements(char **lines, t_game *game)
{
	int	i;

	i = -1;
	while (lines[++i] && is_map_line(lines[i]) == false)
	{
		if (is_line_empty(lines[i]) == true)
			continue ;
		game->parsing.tokens = ft_split_gc(lines[i], ' ', &game->gc);
		if (!game->parsing.tokens || !game->parsing.tokens[0]
			|| !game->parsing.tokens[1] || game->parsing.tokens[2])
			return (ft_error("Error\nInvalid element line format"));
		if (dispatch_element(&game->parsing, game) == 1)
			return (1);
	}
	if (!game->parsing.found_na || !game->parsing.found_so
		|| !game->parsing.found_we || !game->parsing.found_ea
		|| !game->parsing.found_floor || !game->parsing.found_ceiling)
		return (ft_error("Error\nMissing or duplicate element(s)"));
	return (0);
}
