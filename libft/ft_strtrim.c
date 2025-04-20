/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:44:43 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/04 17:33:26 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *set, char s1_char)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1_char)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_check(set, s1[start]) == 1)
		start++;
	while (end > start && ft_check(set, s1[end - 1]) == 1)
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main (void)
// {
// 	char *s1 = "..6fiasdasd..6";
// 	char *s2 = "..6";
// 	printf("%s", ft_strtrim(s1, s2));
// 	return (0);
// }
