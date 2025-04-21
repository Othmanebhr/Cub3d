/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:15:59 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/12 21:17:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *dest, char *src)
{
	int		i;
	int		j;
	char	*str;

	if (!dest || !src)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_gnl(dest) + ft_strlen_gnl(src) + 1));
	if (str == NULL)
		return (free(dest), NULL);
	i = -1;
	j = 0;
	while (dest[++i] != '\0')
		str[i] = dest[i];
	while (src[j] != '\0')
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(dest);
	return (str);
}

char	*ft_strncpy(char *dest, char *src, char n)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != n)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_get_strchr(char *str, char search)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != search)
		i++;
	if (str[i] == search)
		return (0);
	return (1);
}
