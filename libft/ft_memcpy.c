/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:57:03 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/03 15:14:59 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return ((unsigned char *)dest);
}
// int main()
// {
//     char src[] = "Hello, world!";
//     char dst[20];
//     printf("Before memcpy: %s\n", dst);
//     ft_memcpy(dst, src, sizeof(src));
//     printf("After memcpy: %s\n", dst);

//     return 0;
// }
