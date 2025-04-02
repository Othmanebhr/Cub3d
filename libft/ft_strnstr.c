/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:45:11 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/27 15:27:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < n)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char s1[] = "";
// 	char s2[] = "";
// 	//printf("%s\n", ft_strnstr(s1, s2, sizeof(s1)));
// 	printf("%s\n", ft_strnstr(s1, s2, 0));
// }
