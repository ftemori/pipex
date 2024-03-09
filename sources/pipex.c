/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftemori <ftemori@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:23:22 by ftemori           #+#    #+#             */
/*   Updated: 2023/11/15 12:23:25 by ftemori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*commandret(char *argv, int path_count, char *path)
{
	int		i;
	int		k;
	char	*command;

	i = 0;
	k = 0;
	while (path[i] != '/' && path[i] != '\0')
		i++;
	if (path[i] == '\0')
		return (NULL);
	command = paths_to_array(path + i, path_count, argv);
	return (command);
}

char	*flagret(char *s)
{
	int		i;
	int		k;
	int		len;
	char	*flag;

	i = 0;
	k = 0;
	while (s[i] != ' ' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	i++;
	len = ft_strlen(s + i);
	flag = malloc(len + 1);
	while (s[i] != '\0')
	{
		flag[k] = s[i];
		k++;
		i++;
	}
	flag[k] = '\0';
	return (flag);
}

int	inputcheck(int ac, char **av)
{
	if (ac < 5)
	{
		perror("Not enough arguments");
		return (-1);
	}
	if (access(av[1], F_OK) == -1)
	{
		perror("ERROR: wrong input file");
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	id;
	int	pfd[2];
	int	i;
	int	infd;

	if (inputcheck(ac, av) == -1)
		return (-1);
	i = 1;
	infd = ft_open(av[1]);
	dup2(infd, 0);
	while (ft_strcmp(av[++i], outfile_det(av)) != 0)
	{
		pipe(pfd);
		id = fork();
		if (id == 0)
		{
			if (child_process(av, pfd[1], i) == -1)
				return (-1);
			child_executer(av[i], envp);
		}
		else
			if (parent_process(pfd[0], pfd[1]) == -1)
				return (-1);
	}
	return (0);
}
