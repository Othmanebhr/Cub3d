/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:06:53 by obouhour          #+#    #+#             */
/*   Updated: 2024/05/21 11:55:18 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int letter)
{
	if (letter >= 'a' && letter <= 'z')
		letter -= 32;
	return (letter);
}
/*
int main (void)
{
    char a = 'a';
    printf("%c\n", ft_toupper(a));
    return(0);
}*/