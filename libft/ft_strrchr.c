/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:04:49 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/04 12:18:35 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search)
{
	int		i;
	char	c;

	c = (char)search;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}
/*
int main (void)
{
    const char str[] = "Ohtmaaane";
    char sh = 'a';
    printf("%s\n", ft_strrchr(str, sh));
    return (0);
}*/
