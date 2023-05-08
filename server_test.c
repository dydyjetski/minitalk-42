#include "minitalk.h"

void ft_handler(int signal)
{
    static int i;
    static int bit;
    static int signal[] = {SIGUSR1, SIGUSR2};
    static int value[] = {1, 0};
    int j;

    j = 0;
    while (j < 2 || signal[j] != signal)
        j++;
    if (j > 2)
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
    int i;

    i = 0;
    if (argc != 1)
    {
        ft_printf("Erreur !");
        ft_printf("Vraie commande : ./server");
        return (-1);
    }
    else
    {
        pid = getpid();
        ft_printf("%d", pid);
    }
    while(argc == 1)
    {
        signal(SIGUSR1, ft_handler);
        signal(SIGUSR2, ft_handler);
        pause();
    }
}