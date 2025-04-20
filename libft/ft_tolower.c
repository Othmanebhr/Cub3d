/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:06:13 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/03 15:37:56 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int letter)
{
	if (letter >= 'A' && letter <= 'Z')
		letter += 32;
	return (letter);
}
/*
int main (void)
{
    char a = 'd';
    printf("%c\n", ft_toupper(a));
    return(0);
}*/
