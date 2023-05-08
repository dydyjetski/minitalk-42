/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:01:02 by dmeurant          #+#    #+#             */
/*   Updated: 2023/04/30 17:01:03 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int check_pid(char *s)
{
    int i;
    int pid;

	pid = 0;
	i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
        {
            ft_printf("Erreur, le pid doit etre un nombre");
            return 0;
        }
        pid = pid * 10 + (s[i] - '0');
        i++;
    }
    return pid;
}

void ft_send_bit (int pid, char s)
{
    int bit;
    int mask;

    bit = 0;
    mask = 1;
    while (bit < 8)
    {
        if (s / mask % 2 == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
		usleep(100);
        bit++;
        mask *= 2;
    }
}

int main (int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = check_pid(argv[1]);
        if (pid < 0)
            return 0;
        while(argv[2][i])
        {
            ft_send_bit(pid, argv[2][i]);
            i++;
        }
    }
    else
    {
        ft_printf("Erreur");
		return 0;
    }
    return 0;
}