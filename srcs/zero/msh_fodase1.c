/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_fodase1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:01:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 13:57:52 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_router(t_shell *sh, t_cmd *cmd);

static void	msh_dupfds(int redir, int fd, int src);

static void	msh_resetsignal(void);

void	msh_fodase1(t_shell *sh, t_cmd *cmd, int *prevpipe, t_list **lst)
{
	int		fd[2];
	int		cpid;

	pipe(fd);
	cpid = fork();
	(void) lst;
	if (cpid == 0)
	{
		msh_resetsignal();
		close (fd[IN]);
		msh_dupfds(cmd->fdout.ffd, fd[OUT], STDOUT_FILENO);
		close (fd[OUT]);
		msh_dupfds(cmd->fdin.ffd, *prevpipe, STDIN_FILENO);
		close (*prevpipe);
		msh_router(sh, cmd);
	}
	else
	{
		//ft_lstadd_back(lst, ft_lstnew(0, cpid));
		close (fd[OUT]);
		close (*prevpipe);
		*prevpipe = fd[IN];
	}
}

static void	msh_resetsignal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

static void	msh_dupfds(int redir, int fd, int src)
{
	if (redir != -2)
		dup2(redir, src);
	else
		dup2(fd, src);
}

static void	msh_router(t_shell *sh, t_cmd *cmd)
{
	void	*builtin;
	char	*pathname;

	builtin  = msh_isbuiltin(*cmd->args);
	if (builtin)
		;
	else
	{
		pathname = msh_getpathname(*cmd->args, sh->env->var_list);
		execve(pathname, cmd->args, sh->env->var_list);
	}
	close (cmd->fdout.ffd);
	close (cmd->fdin.ffd);
	msh_shclean(sh);
}
