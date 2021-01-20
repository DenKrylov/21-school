#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

typedef struct	s_all
{
	char		**args;
	int			pipe;
	int			semicolon;
	int			fd[2];
	int			stdin;
	int			stdout;
}				t_all;

int				g_status;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**str_to_array(char **array, char *str)
{
	char 	**new_array;
	int		i;

	i = 0;
	while (array != NULL && array[i] != NULL)
		i++;
	if (!(new_array = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (array != NULL && array[i] != NULL)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = str;
	i++;
	new_array[i] = NULL;
	if (array != NULL)
		free(array);
	array = NULL;
	return (new_array);
}

void	init_args(t_all *all)
{
	all->args = NULL;
	all->pipe = 0;
	all->semicolon = 0;
	all->stdin = dup(1);
	all->stdout = dup(0);
	all->fd[0] = -1;
	all->fd[1] = -1;
}

void	clear_args(t_all *all)
{
	if (all->args != NULL)
		free(all->args);
	all->args = NULL;
	all->pipe = 0;
	all->semicolon = 0;
}

int	shell_cd(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
		i++;
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		g_status = 1;
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, args[1], ft_strlen(args[1]));
		write(2, "\n", 1);
		g_status = 1;
		return (1);
	}
	return (0);
}

int	launch(t_all *all, char **env)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid == 0)
	{
		if (all->pipe)
		{
			dup2(all->fd[1], 1);
			if (all->fd[0] >= 3)
				close(all->fd[0]);
		}
		if (execve(all->args[0], all->args, env) == -1)
		{
			write(2, "error: cannot execute ", 22);
			write(2, all->args[0], ft_strlen(all->args[0]));
			write(2, "\n", 1);
			if (all->fd[1] >= 3)
				close(all->fd[1]);
			exit(1);
		}
		if (all->fd[1] >= 3)
			close(all->fd[1]);
	}
	else if (pid < 0)
	{
		write(2, "error: fatal\n", 13);
		clear_args(all);
		if (all->fd[0] >= 3)
			close(all->fd[0]);
		if (all->fd[1] >= 3)
			close(all->fd[1]);
		exit(1);
	}
	else
	{
		if (all->pipe)
			dup2(all->fd[0], 0);
		if (all->fd[1] >= 3)
			close(all->fd[1]);
		waitpid(pid, &stat, WUNTRACED);
		while (!WIFEXITED(stat) && !WIFSIGNALED(stat))
			waitpid(pid, &stat, WUNTRACED);
		g_status = WEXITSTATUS(stat);
		if (all->fd[0] >= 3)
			close(all->fd[0]);
		if (!all->pipe)
		{
			dup2(all->stdin, 1);
			dup2(all->stdout, 0);
		}
	}
	return (0);
}

int	parse_args(t_all *all, char **argv, char **env)
{
	int	pos;
	int status;

	pos = 1;
	status = 1;
	while (status)
	{
		while (argv[pos] != NULL && strcmp(argv[pos], ";") && strcmp(argv[pos], "|"))
		{
			if (!(all->args = str_to_array(all->args, argv[pos])))
			{
				write(2, "error: fatal\n", 13);
				clear_args(all);
				exit(1);
			}
			pos++;
		}
		if (argv[pos] != NULL && !strcmp(argv[pos], "|"))
			all->pipe = 1;
		if (argv[pos] != NULL && !strcmp(argv[pos], ";"))
			all->semicolon = 1;
		if (all->pipe)
			pipe(all->fd);
		if (all->args != NULL && !strcmp(all->args[0], "cd"))
			shell_cd(all->args);
		else if (all->args != NULL)
			launch(all, env);
		if (!all->semicolon && !all->pipe)
			status = 0;
		clear_args(all);
		pos++;
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
    t_all	all;

	g_status = 0;
	if (argc > 1)
	{
		init_args(&all);
		parse_args(&all, argv, env);	
	}
	return (g_status);
}