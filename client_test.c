int check_pid(char *s)
{
    int i;
    int pid;

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


int main (int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = check_pid(argv[1]);
        if (pid < 0)
            return ;
        while(argv[2][i])
        {
            ft_send_bit(pid, argv[2][i]);
            i++;
        }
    }
    else
    {
        ft_printf("Erreur");
    }
    return 0;
}