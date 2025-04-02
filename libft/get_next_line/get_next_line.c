/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:13:46 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/26 19:20:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncrush(char *str, char c)
{
	int		y;
	int		count;
	char	*str2;

	y = 0;
	count = 0;
	while (str[count] != c)
		count++;
	count++;
	str2 = malloc(sizeof(char) * ((ft_strlen_gnl(str) - count) + 1));
	if (str2 == NULL)
		return (NULL);
	while (str[count])
	{
		str2[y] = str[count];
		y++;
		count++;
	}
	str2[y] = '\0';
	free (str);
	return (str2);
}

int	ft_size_of_temp(char *str, char c)
{
	int	count;

	count = 0;
	while (str[count] != c)
		count++;
	count++;
	return (count);
}

char	*ft_read_file(char *stat, int fd)
{
	char	*buffer;
	int		checker;

	if (!stat)
	{
		stat = malloc(1 * sizeof(char));
		if (!stat)
			return (NULL);
		stat[0] = '\0';
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	checker = 1;
	while (checker > 0 && ft_get_strchr(stat, '\n'))
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
			return (free(buffer), free(stat), NULL);
		buffer[checker] = '\0';
		stat = ft_strjoin_gnl(stat, buffer);
	}
	return (free (buffer), stat);
}

char	*extract_line(char **stat)
{
	char	*temp;

	temp = NULL;
	if (ft_get_strchr(*stat, '\n') == 0)
	{
		temp = malloc(sizeof(char) * (ft_size_of_temp(*stat, '\n') + 1));
		if (!temp)
			return (NULL);
		temp = ft_strncpy(temp, *stat, '\n');
		*stat = ft_strncrush(*stat, '\n');
	}
	else if (ft_get_strchr(*stat, '\n') == 1)
	{
		temp = malloc(sizeof(char) * (ft_strlen_gnl(*stat) + 1));
		if (!temp)
			return (NULL);
		temp = ft_strncpy(temp, *stat, '\0');
		free(*stat);
		*stat = NULL;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = ft_read_file(stat, fd);
	temp = extract_line(&stat);
	if (temp && temp[0] == '\0')
		return (free(temp), NULL);
	return (temp);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }