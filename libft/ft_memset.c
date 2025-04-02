/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:00:56 by obouhour          #+#    #+#             */
/*   Updated: 2024/05/21 14:41:59 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)ptr)[i] = (unsigned char)val;
		i++;
	}
	return (ptr);
}
/*
int main(void)
{
    char array[10];

    ft_memset(array, '5', 4);
    printf("%s\n", array);
    return (0);
}*/