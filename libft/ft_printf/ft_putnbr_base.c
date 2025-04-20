/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:14:23 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/12 21:08:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_b(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len_base;
	int				len;
	unsigned int	unbr;

	len = 0;
	len_base = ft_strlen_printf(base);
	unbr = (unsigned int)(nbr);
	if (unbr < len_base)
		len += ft_putchar_b(base[unbr]);
	if (unbr >= len_base)
	{
		len += ft_putnbr_base(unbr / len_base, base);
		len += ft_putnbr_base(unbr % len_base, base);
	}
	return (len);
}
