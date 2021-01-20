#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

int get_next_line(char **line)
{
    char c;
    int readed;
    char *tmp;
    int i = 0;

    if((readed = read(0, &c, 1)) < 0)
        return(-1);
    if(!(*line = malloc(sizeof(char*))))
        return(0);
    line[0][0] = '\0';
    while(c != '\n' && readed != 0)    
    {
        tmp = *line;
        if(!(*line = malloc(ft_strlen(tmp) * sizeof(char*) + 2)))
            return(-1);
        while(tmp[i])
        {
            line[0][i] = tmp[i];
            i++;
        }
        line[0][i] = c;
        line[0][++i] = '\0';
        free(tmp);
        tmp = NULL;
        i = 0;
        readed = read(0, &c, 1);
    }
    if(c == '\n')
        return(1);
    if(readed == 0)
        return(0);
    return(-1);
}

int main(void)
{
    int r;
    char *line;

    line = NULL;
    while((r = get_next_line(&line)) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s\n", line);
    free(line);
    line = NULL;
    return (0);
}