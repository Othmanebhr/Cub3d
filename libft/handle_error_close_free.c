/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_close_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:23:38 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/30 17:24:02 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_error_close_free(char *str, int fd, char **map)
{
	free_dbl_tab(map);
	if (fd >= 0)
		close(fd);
	perror(str);
	exit(EXIT_FAILURE);
}
