/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:48:23 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/28 20:48:23 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_handler(int signal)
{
    static int i;
    static int bit;
    static int signals[] = {SIGUSR1, SIGUSR2};
    static int value[] = {1, 0};
    int j;

    j = 0;
    while (j < 2 && signals[j] != signal)
        j++;
    if (j == 2)
        return ;
    i = i | (value[j] << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main (int argc, char **argv)
{
    int pid;

	(void)argv;
    if (argc != 1)
    {
        ft_printf("Erreur !");
        ft_printf("Vraie commande : ./server");
        return (0);
    }
    pid = getpid();
    ft_printf("%d", pid);
    while(argc == 1)
    {
        signal(SIGUSR1, ft_handler);
        signal(SIGUSR2, ft_handler);
        pause();
    }
	return 0;
}