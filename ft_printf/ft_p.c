/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:44:18 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/22 00:44:19 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_ptr_len(unsigned long int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_ptr_calc(unsigned long int n)
{
	if (n >= 16)
	{
		ft_ptr_calc(n / 16);
		ft_ptr_calc(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	print;

	print = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		print += write(1, "0x", 2);
		ft_ptr_calc(ptr);
		print += ft_ptr_len(ptr);
	}
	return (print);
}
