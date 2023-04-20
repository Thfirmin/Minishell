/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:21:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 11:24:30 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_heredoc(char *eof)
{
	char	*line;
	int		fd[2];

	if (pipe(fd))
		return (msh_perror("here-doc", 0)); // error for pipe
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			msh_perror("warning",\
				"here-document delimited by end-of-file (wanted \'%s\')", eof);
		}
			return (fd[0]); // error for eof
		if (!ft_strncmp(eof, line, ft_strlen(eof) + 1))
			break ;
		write(fd[1], line, ft_strlen(line));
		free (line);
	}
	free (line);
	return (fd[0]);
}
