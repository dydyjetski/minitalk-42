/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:58:56 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/22 00:58:56 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_return_write(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_put_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count += ft_put_unsigned(n / 10);
		count += ft_put_unsigned(n % 10);
	}
	else
	{
		c = n + '0';
		count += ft_return_write(c, 1);
	}
	return (count);
}
