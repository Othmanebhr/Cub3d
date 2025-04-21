/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:29 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/03 15:57:31 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	len_source;

	i = 0;
	len_source = ft_strlen((char *)src);
	if (len == 0)
		return (len_source);
	while (i < len -1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_source);
}

// int main (void)
// {
// 	char dest[] = "Othmane";
// 	const char src[] = "123456789";
// 	printf("%d\n", ft_strlcpy(dest, src, 0));
// 	printf("%s\n", dest);
// 	return (0);
// }
