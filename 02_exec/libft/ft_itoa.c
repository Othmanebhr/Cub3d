/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:48:28 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:37 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_number(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;
	size_t	neg;

	num = n;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		num *= -1;
	}
	len = len_number(num) + neg;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
// int	main (void)
// {
// 	int	n = 0;
// 	char *str;

// 	printf("%s\n", str = ft_itoa(n));
// 	return (0);
// }
