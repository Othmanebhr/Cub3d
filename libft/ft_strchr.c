/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:01:43 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/04 11:53:44 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	int		i;
	char	c;

	c = (char)search;
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

// int main(void)
// {
//     const char str[] = "";
//     char sh = 'a';
//     printf("%s\n", ft_strchr(str, sh));
//     return(0);
// }
