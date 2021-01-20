#include <unistd.h>

void ft_union(char *argv)
{
    static char c[255] = {0};
    int i;

    i = 0;
    while (argv[i])
    {
        if(!c[(unsigned char)argv[i]])
        {
            c[(unsigned char)argv[i]] = 1;
            write(1, &argv[i], 1);
        }
        i++;
    }   
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        ft_union(argv[1]);
        ft_union(argv[2]);
    }
    write(1, "\n", 1);
    return (0);
}