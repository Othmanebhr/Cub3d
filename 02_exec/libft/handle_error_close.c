/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:22:53 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/30 17:24:05 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_error_close(char *str, int fd)
{
	perror(str);
	if (fd >= 0)
		close(fd);
	exit(EXIT_FAILURE);
}
