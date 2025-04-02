/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:06:40 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/11 12:05:11 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	size_t	len;
	char	*str;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[y])
		ft_strlcpy(&str[i++], &s1[y++], ft_strlen(s1));
	y = 0;
	while (s2[y])
		ft_strlcpy(&str[i++], &s2[y++], len);
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
// 	char *s1 = "12345";
// 	char *s2 = "6789";
// 	printf("%s", ft_strjoin(s1, s2));
// 	free;
// 	return (0);
// }
