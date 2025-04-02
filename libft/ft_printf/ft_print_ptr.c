/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:37:56 by obouhour          #+#    #+#             */
/*   Updated: 2024/06/14 19:28:18 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long adress)
{
	int	len;

	len = 0;
	if (!adress)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_put_ptr(adress);
	return (len);
}

int	ft_put_ptr(unsigned long long adress)
{
	int	len;

	len = 0;
	if (adress >= 16)
	{
		len += ft_put_ptr(adress / 16);
		len += ft_put_ptr(adress % 16);
	}
	else
	{
		if (adress <= 9)
			len += ft_putchar(adress + '0');
		else
			len += ft_putchar(adress - 10 + 'a');
	}
	return (len);
}
