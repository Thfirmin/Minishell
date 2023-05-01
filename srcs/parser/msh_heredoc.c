/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:21:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:12:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_return_heredoc(int fd[2]);

int	msh_heredoc(char *eof)
{
	char	*line;
	int		fd[2];

	if (pipe(fd))
	{
		msh_perror(0, "here_doc", 0);
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			msh_perror(0, "warning", \
				"here-document delimited by end-of-file (wanted \'%s\')", eof);
			return (msh_return_heredoc(fd));
		}
		if (!ft_strncmp(eof, line, ft_strlen(eof) + 1))
			break ;
		else
			ft_putendl_fd(line, fd[OUT]);
		free (line);
	}
	free (line);
	return (msh_return_heredoc(fd));
}

static int	msh_return_heredoc(int fd[2])
{
	close (fd[OUT]);
	return (fd[IN]);
}
