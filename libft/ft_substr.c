/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:46:48 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/11 12:05:30 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (start >= ft_strlen(s))
		size = 0;
	else if (start + len > ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len;
	str = malloc(sizeof (char) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i != size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main (void)
// {
// 	char *str = "123456789";
// 	printf("%s", ft_substr(str, 3, 3));
// 	return (0);
// }
