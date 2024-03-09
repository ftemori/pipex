/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftemori <ftemori@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:23:40 by ftemori           #+#    #+#             */
/*   Updated: 2023/11/15 12:23:45 by ftemori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_open(char *av)
{
	int	fd;

	fd = open(av, O_RDWR | O_CREAT, 0777);
	if (fd < 3)
	{
		perror("ERROR: opening file to read");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_open_truncate(char *av)
{
	int	fd;

	fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 3)
	{
		perror("ERROR: opening file to read");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *buffer, char *content)
{
	int		len;
	int		i;
	char	*temp;

	i = 0;
	len = ft_strlen(content);
	if (!buffer)
		return (content);
	if (len == 0)
	{
		temp = malloc(2);
		temp[0] = *buffer;
		temp[1] = '\0';
		return (temp);
	}
	else 
		temp = malloc(len + 2);
	while (content[i] != '\0')
	{
		temp[i] = content[i];
		i++;
	}
	temp[i] = buffer[0];
	temp[i + 1] = '\0';
	return (temp);
}
