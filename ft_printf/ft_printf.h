/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:45:01 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/15 15:45:36 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putstr(char *c);
void	ft_putchar(char c);
int		ft_puthex(unsigned int num, const char format);
void	ft_putchar(char c);
int		ft_printstr(char *str);
int		ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		ft_print_ptr(unsigned long int ptr);
int		ft_percent(void);
int		ft_put_unsigned(unsigned int num);
int		ft_printchar(int c);
void	ft_putchar_fd(char c, int fd);

#endif
