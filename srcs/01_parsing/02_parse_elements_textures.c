/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse_elements_textures.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:46 by besch             #+#    #+#             */
/*   Updated: 2025/04/25 15:30:40 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_texture_file_ok(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

int	handle_texture(t_parsing *parsing, t_game *game, int idx)
{
	bool	*found;

	if (idx == 0)
		found = &parsing->found_na;
	else if (idx == 1)
		found = &parsing->found_so;
	else if (idx == 2)
		found = &parsing->found_we;
	else if (idx == 3)
		found = &parsing->found_ea;
	else
		return (ft_error("Error\nInvalid texture index"));
	if (*found)
		return (ft_error("Error\nDuplicate texture"));
	*found = true;
	if (is_texture_file_ok(parsing->tokens[1]) == false)
		return (ft_error("Error\nTexture file not accessible"));
	game->textures[idx].path = ft_strdup_gc(parsing->tokens[1], &game->gc);
	return (0);
}
