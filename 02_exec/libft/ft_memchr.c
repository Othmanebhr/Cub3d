/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:47:29 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/03 18:30:00 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int search, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)search;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	int s[] = {1, 2, 3, 4, 5};
// 	int *result = ft_memchr(s, 4, 5);
// 	if (result != NULL)
// 		printf("La valeur a été trouvée à l'adresse : %p\n", (void *)result);
// 	else
// 		printf("La valeur n'a pas été trouvée.\n");
// 	return (0);
// }

// int main(void)
// {
// 	char *str = ft_memchr("bonjour", 'o', 7);
// 	printf ("%s", str);
// }
