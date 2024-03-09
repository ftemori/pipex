/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftemori <ftemori@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:23:53 by ftemori           #+#    #+#             */
/*   Updated: 2023/11/15 12:23:56 by ftemori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>

int		path_len(char *s);
int		ft_open(char *av);
int		ft_strlen(char *s);
int		ft_strlen(char *s);
int		path_counter(char *line);
int		ft_open_truncate(char *av);
int		extract_command(char *str);
int		inputcheck(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
int		main(int ac, char **av, char **envp);
int		child_executer(char *av, char **envp);
int		parent_process(int pfd_zero, int pfd_one);
int		child_process(char **av, int pfd_one, int i);
char	*flagret(char *s);
char	*get_next_line(int fd);
char	*outfile_det(char **av);
char	*paths_line(char **envp);
char	*commandret(char *argv, int path_count, char *path);
char	*command_to_path(char *argv, int len, char *string, int i);
char	*paths_to_array(char *string, int path_count, char *argv);

#endif
