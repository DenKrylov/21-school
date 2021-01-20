#include <unistd.h>
#include <stdio.h>

void ft_inter(char *argv1, char *argv2)
{
    static char c[255] = {0};
    int i;
    int j;

    i = 0;
    while(argv1[i])
    {
        if(!c[(unsigned char)argv1[i]])
        {
            c[(unsigned char)argv1[i]] = 1;
            j = 0;
            while(argv2[j])
            {
                if(argv1[i] == argv2[j])
                {
                    write(1, &argv1[i], 1);
                    break;
                }
                j++;
            }
        }
        i++;
    }
}


int main(int argc, char **argv)
{
    if(argc == 3)
    {
        ft_inter(argv[1], argv[2]);
    }
    write(1, "\n", 1);
    return (0);
}
