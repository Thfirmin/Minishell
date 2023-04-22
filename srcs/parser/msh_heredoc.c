/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:21:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:40:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			return (fd[0]);
		}
		if (!ft_strncmp(eof, line, ft_strlen(eof) + 1))
			break ;
		else
			write (fd[1], line, ft_strlen(line));
		free (line);
	}
	free (line);
	return (fd[0]);
}
