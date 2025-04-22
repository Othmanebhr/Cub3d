/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parse_map_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besch <besch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:31:51 by besch             #+#    #+#             */
/*   Updated: 2025/04/22 17:05:50 by besch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_spawn_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	find_player_pos(char **lines, int start, int end, t_vec2 *pos)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = start - 1;
	while (++i <= end)
	{
		j = -1;
		while (lines[i][++j])
		{
			if (is_spawn_char(lines[i][j]))
			{
				count++;
				pos->x = j;
				pos->y = i;
			}
		}
	}
	if (count == 0)
		return (ft_error("Error\nNo player spawn in map"));
	if (count > 1)
		return (ft_error("Error\nMultiple player spawns in map"));
	return (0);
}

static int	is_spawn_inside(char **lines, int start, int end, t_vec2 pos)
{
	int	len;
	int	px;
	int	py;

	px = (int)pos.x; // colonne
	py = (int)pos.y; // ligne
	len = ft_strlen(lines[py]);
	if (py == start || py == end
		|| px == 0 || px == len - 1)
		return (ft_error("Error\nPlayer spawn on map border"));
	if (lines[py - 1][px] == ' '
		|| lines[py + 1][px] == ' '
		|| lines[py][px - 1] == ' '
		|| lines[py][px + 1] == ' '
		|| lines[py - 1][px] == '\0'
		|| lines[py + 1][px] == '\0')
		return (ft_error("Error\nPlayer spawn not inside the map"));
	return (0);
}

int	check_player_spawn(char **lines, t_game *game, int start, int end)
{
	t_vec2	player_pos;

	player_pos.x = -1;
	player_pos.y = -1;
	// Cherche la position du joueur et vérifie unicité
	if (find_player_pos(lines, start, end, &player_pos) != 0)
		return (1);
	// Vérifie que le spawn n'est pas sur un bord et bien entouré
	if (is_spawn_inside(lines, start, end, player_pos) != 0)
		return (1);

	// Place le joueur au centre de la case (pour le rendu/raycasting)
	game->player.pos.x = player_pos.x + 0.5;
	game->player.pos.y = player_pos.y - start + 0.5;

	// Définit la direction initiale selon la lettre trouvée dans la map
	if (lines[(int)player_pos.y][(int)player_pos.x] == 'N')
		game->player.dir = (t_vec2){0, -1}; // Nord : vers le haut (y négatif)
	else if (lines[(int)player_pos.y][(int)player_pos.x] == 'S')
		game->player.dir = (t_vec2){0, 1};  // Sud : vers le bas (y positif)
	else if (lines[(int)player_pos.y][(int)player_pos.x] == 'E')
		game->player.dir = (t_vec2){1, 0};  // Est : vers la droite (x positif)
	else if (lines[(int)player_pos.y][(int)player_pos.x] == 'W')
		game->player.dir = (t_vec2){-1, 0}; // Ouest : vers la gauche (x négatif)

	// Définit le plan caméra (perpendiculaire à la direction, FOV ~66°)
	game->player.plane.x = game->player.dir.y * -0.66;
	game->player.plane.y = game->player.dir.x * 0.66;

	// Sauvegarde la direction de départ (utile pour reset ou affichage)
	game->player.start_dir = lines[(int)player_pos.y][(int)player_pos.x];

	// Remplace la case de spawn par '0' (case vide) dans la map
	// lines[(int)player_pos.x][(int)player_pos.y] = '0';

	return (0);
}
