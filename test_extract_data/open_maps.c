/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:50:24 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/07 18:00:05 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Extract.h"

static int	count_line(int fd) //A revoir
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

static void	reinitialize_gnl_for_map(t_data *data)
{
	char	*line;

	data->fd = open(data->save_filename, O_RDONLY);
	if (data->fd == -1)
	{
		printf("erro: failed to initialize map\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(data->fd);//NO
	free(line);
	line = get_next_line(data->fd);//SO
	free(line);
	line = get_next_line(data->fd);//WE
	free(line);
	line = get_next_line(data->fd);//EA
	free(line);
	line = get_next_line(data->fd);//\n
	free(line);
	line = get_next_line(data->fd);//C
	free(line);
	line = get_next_line(data->fd);//F
	free(line);
	line = get_next_line(data->fd);//\n
	free(line);
}

static void	get_direction(t_data *data)
{
	char	*line;

	data->NO = get_next_line(data->fd);
	data->SO = get_next_line(data->fd);
	data->WE = get_next_line(data->fd);
	data->EA = get_next_line(data->fd);
	printf("NO = %s\n", data->NO);
	line = get_next_line(data->fd); //Sauter le saut de ligne
	free(line);
}

static void	get_ceiling_floor(t_data *data)
{
	char	*line;

	data->ceiling = get_next_line(data->fd);
	data->floor = get_next_line(data->fd);
	line = get_next_line(data->fd);//Sauter le saut de ligne
	free(line);
}

static void	get_map(t_data *data)
{
	int	i;

	i = 0;
	data->size_map = count_line(data->fd);
	data->map = malloc(sizeof(char *) * (data->size_map + 1));
	close(data->fd);
	reinitialize_gnl_for_map(data);
	while (i < data->size_map)
	{
		data->map[i] = get_next_line(data->fd);
		i++;
	}
	data->map[i] = NULL;
}

// static void	print_test(t_data data)
// {
// 	int	i = 0;

// 	printf("%s", data.NO);
// 	printf("%s", data.SO);
// 	printf("%s", data.WE);
// 	printf("%s", data.EA);
// 	printf("%s", data.ceiling);
// 	printf("%s", data.floor);
// 	while (i < data.size_map)
// 	{
// 		printf("%s", data.map[i]);
// 		i++;
// 	}
// }

void	test_parse(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		printf("format: ./cub3d 'map.cub'\n");
		exit(EXIT_FAILURE);
	}
	/*Parse*/
	data->fd = open(av[1], O_RDONLY);
	if (data->fd == -1)
	{
		printf("error: Failed to open file");
		exit(EXIT_FAILURE);
	}
	data->save_filename = ft_strdup(av[1]);	
	get_direction(data);
	get_ceiling_floor(data);
	get_map(data);
	// print_test(data);
	// free_dbl_tab(data.map);
	close(data->fd);
}

/* Compile : cc open_maps.c -I../libft -L../libft -lft */
//Ne pas oublier de mak la libft avant de compiler//