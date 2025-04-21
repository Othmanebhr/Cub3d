/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:38:09 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/11 12:17:37 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	char	*ptr;

	if (nmemb && n && nmemb > (UINT_MAX / n))
		return (NULL);
	ptr = malloc(nmemb * n);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * n);
	return (ptr);
}

// int main(void)
// {
// 	char 	*array;
// 	size_t	nmemb;
// 	size_t	n;
// 	size_t	i;

// 	nmemb = 1;
// 	n = sizeof(int);
// 	array = (char *)ft_calloc(nmemb, n);
// 	printf("%s", array);
// }
