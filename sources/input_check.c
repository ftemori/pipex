/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:21:54 by ftemori           #+#    #+#             */
/*   Updated: 2024/01/21 09:46:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	path_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != ':' && s[i] != '\n')
		i++;
	return (i);
}

int	child_process(char **av, int pfd_one, int i)
{
	char	*outfile;
	int		fdout;

	outfile = NULL;
	outfile = outfile_det(av);
	if (ft_strcmp(av[i + 1], outfile) == 0)
	{
		fdout = ft_open_truncate(outfile);
		dup2(fdout, 1);
	}
	else
	{
		if (dup2(pfd_one, 1) == -1 || close(pfd_one) == -1)
			return (-1);
	}
	return (0);
}

int	parent_process(int pfd_zero, int pfd_one)
{
	if (waitpid(0, NULL, 0) == -1 || dup2(pfd_zero, 0) == -1
		|| close(pfd_one) == -1 || close(pfd_zero) == -1)
		return (-1);
	return (0);
}

int	child_executer(char *av, char **envp)
{
	char	*command;
	char	*flag;
	char	*exec_av[4];
	char	*path;
	int		path_count;

	path = paths_line(envp);
	path_count = path_counter(path);
	command = commandret(av, path_count, path);
	flag = flagret(av);
	exec_av[0] = command;
	exec_av[1] = flag;
	exec_av[2] = NULL;
	if (execve(command, exec_av, NULL) == -1)
		perror("execveERROR");
	return (0);
}

char	*outfile_det(char **av)
{
	int	i;

	i = 0;
	while (av[i + 1] != NULL)
		i++;
	return (av[i]);
}

/* char	*path_pointer(char **envp, t_envp *env)
{
	char	*path;
	char	*command;
	int		i;

	path = paths_line(env->envp);
	i = path_counter(path);
	command = commandret(envp, i, path);
	return (NULL);
} */