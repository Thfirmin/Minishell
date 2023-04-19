/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:34:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/19 15:02:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_clean(t_cmd **cmd);

static void	msh_print(t_cmd *cmd);

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*node;
	(void) argc;
	(void) argv;
	(void) envp;

	node = msh_parser("<ola cat >> file 3 fds >> /dev/null>\">mundo >>ola\"");
	msh_print(node);
	msh_clean(&node);
	return (0);
}

static void	msh_print(t_cmd *cmd)
{
	printf ("cmd: %p\nfdin.fd = %d\nfdin.nm = %s\nfdout.fd = %d\nfdout.nm = %s\n", cmd, cmd->fdin.ffd, cmd->fdin.fnm, cmd->fdout.ffd, cmd->fdout.fnm);
}
static void	msh_clean(t_cmd **cmd)
{
	t_cmd	*node;
	t_cmd	*next;

	node = *cmd;
	if (!node)
		return ;
	while (node)
	{
		next = node->next;
		if (node->fdin.ffd != -2)
			close (node->fdin.ffd);
		if (node->fdout.ffd != -2)
			close (node->fdout.ffd);
		free (node->fdin.fnm);
		free (node->fdout.fnm);
		free (node);
		node = next;
	}
	*cmd = 0;
}
