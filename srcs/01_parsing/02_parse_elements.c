/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:48 by besch             #+#    #+#             */
/*   Updated: 2025/04/21 19:31:49 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_map_line(const char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	// Ignore les espaces en début de ligne
	while (line[i] == ' ')
		i++;
	// Si la ligne est vide ou ne contient que des espaces, ce n'est pas une map
	if (line[i] == '\0')
		return (false);
	// Vérifie que la ligne ne contient QUE des caractères valides pour la map
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '0' && line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static int	dispatch_element(t_parse_elements *pe, t_game *game)
{
	if (ft_strcmp(pe->tokens[0], "NO") == 0)
		return (handle_texture(pe, game, 0));
	else if (ft_strcmp(pe->tokens[0], "SO") == 0)
		return (handle_texture(pe, game, 1));
	else if (ft_strcmp(pe->tokens[0], "WE") == 0)
		return (handle_texture(pe, game, 2));
	else if (ft_strcmp(pe->tokens[0], "EA") == 0)
		return (handle_texture(pe, game, 3));
	else if (ft_strcmp(pe->tokens[0], "F") == 0
		|| ft_strcmp(pe->tokens[0], "C") == 0)
		return (handle_color(pe, game));
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
	t_parse_elements	pe;
	int					i;

	ft_memset(&pe, 0, sizeof(t_parse_elements));
	i = -1;
	while (lines[++i] && is_map_line(lines[i]) == false)
	{
		if (is_line_empty(lines[i]) == true)
			continue ;
		pe.tokens = ft_split_gc(lines[i], ' ', &game->gc);
		if (!pe.tokens || !pe.tokens[0] || !pe.tokens[1] || pe.tokens[2])
			return (ft_error("Error\nInvalid element line format"));
		if (dispatch_element(&pe, game) == 1)
			return (1);
	}
	if (!pe.found_na || !pe.found_so || !pe.found_we || !pe.found_ea
		|| !pe.found_floor || !pe.found_ceiling)
		return (ft_error("Error\nMissing or duplicate element(s)"));
	return (0);
}
