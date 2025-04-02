/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:48:00 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/11 11:55:01 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) str)[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int main(void)
{
    char str[] = "123456789";
    ft_bzero(str, 5);
    printf("%s\n", str);
    return (0);
}*/
