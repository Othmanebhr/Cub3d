/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:50:24 by obouhour          #+#    #+#             */
/*   Updated: 2025/04/02 17:11:32 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Extract.h"

int	count_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

int main(int ac, char **av)
{
	int		i;
	t_data	data;
	
	if (ac != 2)
	return (printf("format: ./cub3d 'map.cub'\n"));
	/*Parse*/
	i = 0;
	data.fd = open(av[1], O_RDONLY);
	if (data.fd == -1)
		return (printf("error: Failed to open"), 1);
	data.size = count_line(data.fd);
	data.tab = malloc(sizeof(char *) * (data.size + 1));
	while (i < data.size)
	{
		data.tab[i] = get_next_line(data.fd);
		i++;
	}
	i = 0;
	while (i < data.size)
	{
		printf("%s\n", data.tab[i]);
		i++;
	}
	free_dbl_tab(data.tab);
	close(data.fd);
	return (0);
}

/* Compile : cc open_maps.c -o cub3d -I../libft -L../libft -lft */