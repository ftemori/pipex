/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftemori <ftemori@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:17:55 by ftemori           #+#    #+#             */
/*   Updated: 2023/11/15 16:17:56 by ftemori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*paths_line(char **envp)
{
	int		i;
	char	*paths;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strcmp("PATH=", envp[i]) == 0)
		{
			paths = envp[i];
			return (paths);
		}
		i++;
	}
	return (NULL);
}

int	path_counter(char *line)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ':')
			k++;
		i++;
	}
	return (k + 1);
}

int	extract_command(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (i);
}

char	*command_to_path(char *argv, int len, char *string, int i)
{
	int		k;
	int		comm;
	char	*s;

	k = 0;
	comm = extract_command(argv) + 1;
	s = malloc(len + comm + 2);
	while (len > 0)
	{
		s[k] = string[i];
		k++;
		i++;
		len--;
	}
	s[k] = '/';
	k++;
	i = 0;
	while (--comm > 0)
	{
		s[k] = argv[i];
		k++;
		i++;
	}
	s[k] = '\0';
	return (s);
}

char	*paths_to_array(char *string, int path_count, char *argv)
{
	int		i;
	int		k;
	int		m;
	int		len;
	char	*command;

	i = 0;
	k = 0;
	m = 0;
	len = 1;
	while (path_count > 0)
	{
		len = path_len(string + i);
		command = command_to_path(argv, len, string, i);
		if (access(command, F_OK) == 0)
			break ;
		i += len + 1;
		path_count--;
		m++; 
	}
	return (command);
}
