/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhour <obouhour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:46:47 by obouhour          #+#    #+#             */
/*   Updated: 2024/08/09 22:56:14 by obouhour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_conversions(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar('%'), ft_putchar(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		print;

	va_start(args, format);
	i = 0;
	print = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print += ft_conversions(format[i + 1], args);
			i++;
		}
		else
			print += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (print);
}

// int main()
// {
// 	ft_printf("%s %d %u %x %X %% %p %c\n", "salut", 12, 23, 34, 56, NULL, 'c');
// 	printf("%s %d %u %x %X %% %p %c\n", "salut", 12, 23, 34, 56, NULL, 'c');
// }

// #include <stdio.h>
// int	main(void)
// {
	// char *str = "12";
	// int y = ft_printf(str);
	// printf("\n");
	// int z = printf(str);
	// ft_printf("\n");
	// ft_printf("ft_printf :%s, valeur : %x\n", str);
	// printf("printf :%s, valeur : %x\n", str);

	// printf("=====================================\n");

	// ft_printf("%!\n");
	// printf("%!\n");

	// printf("=====================================\n");

	// int a = 12;
	// ft_printf("ft_printf :%d\n", a);
	// printf("printf :%d\n", a);
	// return (0);

	// printf("=====================================\n");

	// int b = -42;
	// ft_printf("ft_printf hexa : %x\n", b);
	// printf("printf hexa : %x\n", b);

	// printf("=====================================\n");

	// int c = 10;
	// int *ptr = &c;
	// ft_printf("adress de la variable c avec mon ft_printf: %p\n", ptr);
	// printf("adress de la variable c avec printf: %p\n", ptr);

	// printf("=====================================\n");

	// int c_1 = ft_printf("%p\n", ptr);
	// int c_2 = printf("%p\n", ptr);
	// ft_printf("%d\n", c_1);
	// printf("%d\n", c_2);

	// printf("=====================================\n");

	// void *ptr2 = NULL;
	// int abc = ft_printf("%p\n", ptr2);
	// int bcd = printf("%p\n", ptr2);

	// printf("=====================================\n");

	// ft_printf("%d\n", abc);
	// printf("%d\n", bcd);

	// printf("=====================================\n");

// 	int oth = -12236;

// 	ft_printf("%u\n", oth);
// 	printf("%u\n", oth);
// }
