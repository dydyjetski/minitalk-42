/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:54:31 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/22 00:54:33 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_positive_int(int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += print_positive_int(n / 10);
	}
	ft_putchar((n % 10) + '0');
	len++;
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	len += print_positive_int(n);
	return (len);
}
