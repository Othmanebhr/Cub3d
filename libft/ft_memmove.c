/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:21:15 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/04 17:44:05 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long	i;

	i = n - 1;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	else
	{
		while (i >= 0)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i--;
		}
		return (dest);
	}
	return (dest);
}
// int main()
// {
//     char src[] = "lorem ipsum dolor sit amet";
//     char *dest;
//     dest = ft_memmove(dest, src, 8);
//     printf("mine = %s\n", dest);
// }
