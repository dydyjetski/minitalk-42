/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:43:18 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/21 19:43:19 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char form)
{
	int	print;

	print = 0;
	if (form == 'c')
		print += ft_printchar(va_arg(args, int));
	else if (form == 's')
		print += ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		print += ft_print_ptr(va_arg(args, unsigned long int));
	else if (form == 'd' || form == 'i')
		print += ft_putnbr(va_arg(args, int));
	else if (form == 'u')
		print += ft_put_unsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		print += ft_puthex(va_arg(args, unsigned int), form);
	else if (form == '%')
		print += ft_percent();
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print;
	va_list	args;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print += ft_format(args, str[i + 1]);
			i++;
		}
		else
			print += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
