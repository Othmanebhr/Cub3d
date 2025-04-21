/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:23:21 by obouhour          #+#    #+#             */
/*   Updated: 2024/10/12 20:58:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_conversions(char format, va_list args);
int	ft_print_ptr(unsigned long long adress);
int	ft_put_ptr(unsigned long long adress);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_strlen_printf(const char *s);

#endif
