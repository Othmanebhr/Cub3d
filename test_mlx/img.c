/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:36:30 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/15 18:44:55 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mlx.h"

void	free_img(t_game *game)
{
	if (game->imgs)
	{
		if (game->imgs->NO_img)
			mlx_destroy_image(game->mlx, game->imgs->NO_img);
		if (game->imgs->SO_img)
			mlx_destroy_image(game->mlx, game->imgs->SO_img);
		if (game->imgs->WE_img)
			mlx_destroy_image(game->mlx, game->imgs->WE_img);
		if (game->imgs->EA_img)
			mlx_destroy_image(game->mlx, game->imgs->EA_img);
		free(game->imgs);
	}
}

static void	trim_trailing_whitespace(char *str) //a retirer une fois le parsing fais
{
	size_t	len;
	
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' 
			|| str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
}

static void	init_check_struct(t_game *game)
{
	game->imgs->NO_img = NULL;
	game->imgs->SO_img = NULL;
	game->imgs->WE_img = NULL;
	game->imgs->EA_img = NULL;
	if (!game->data || !game->data->NO || !game->data->SO || 
		!game->data->WE || !game->data->EA)
		close_window(game, "error: Invalid texture paths");
	trim_trailing_whitespace(game->data->NO);// a retirer post parsing
	trim_trailing_whitespace(game->data->SO);
	trim_trailing_whitespace(game->data->WE);
	trim_trailing_whitespace(game->data->EA);
}

void	init_img(t_game *game) //ajout de protection pour les adresses
{
	int	width;
	int	height;

	game->imgs = malloc(sizeof(t_img));
	if (!game->imgs)
		close_window(game, "error: Failed to initialize img");
	init_check_struct(game);
	game->imgs->NO_img = mlx_xpm_file_to_image(game->mlx,game->data->NO,&width,&height);
	if (!game->imgs->NO_img)
		close_window(game, "error: Failed to load NO texture");
	game->imgs->NO_addr = mlx_get_data_addr(game->imgs->NO_img, &game->imgs->bpp, &game->imgs->line_len, &game->imgs->endian);
	game->imgs->SO_img = mlx_xpm_file_to_image(game->mlx,game->data->SO,&width,&height);
	if (!game->imgs->SO_img)
		close_window(game, "error: Failed to load SO texture");
	game->imgs->SO_addr = mlx_get_data_addr(game->imgs->SO_img, &game->imgs->bpp, &game->imgs->line_len, &game->imgs->endian);
	game->imgs->WE_img = mlx_xpm_file_to_image(game->mlx,game->data->WE,&width,&height);
	if (!game->imgs->WE_img)
		close_window(game, "error: Failed to load WE texture");
	game->imgs->WE_addr = mlx_get_data_addr(game->imgs->WE_img, &game->imgs->bpp, &game->imgs->line_len, &game->imgs->endian);
	game->imgs->EA_img = mlx_xpm_file_to_image(game->mlx,game->data->EA,&width,&height);
	if (!game->imgs->EA_img)
		close_window(game, "error: Failed to load EA texture");
	game->imgs->EA_addr = mlx_get_data_addr(game->imgs->EA_img, &game->imgs->bpp, &game->imgs->line_len, &game->imgs->endian);
}
