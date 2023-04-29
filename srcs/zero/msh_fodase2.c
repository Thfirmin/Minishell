/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_fodase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:42:46 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 20:58:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_waitpids(t_list **lst);

void	msh_router(t_shell *sh, t_cmd *cmd);

void	msh_dupfds(int redir, int fd, int src);

void	msh_resetsignal(void);

void	msh_fodase2(t_shell *sh, t_cmd *cmd, int prevpipe, t_list **lst)
{
	int		cpid;

	cpid = fork();
	(void) prevpipe;
	if (!cpid)
	{
		msh_resetsignal();
		msh_dupfds(cmd->fdout.ffd, STDOUT_FILENO, STDOUT_FILENO);
		msh_dupfds(cmd->fdin.ffd, prevpipe, STDIN_FILENO);
		close (prevpipe);
		msh_router(sh, cmd);
	}
	else
	{
		ft_lstadd_back(lst, ft_lstnew(&cpid));
		close (prevpipe);
		msh_waitpids(lst);
	}
}

void	msh_resetsignal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	msh_dupfds(int redir, int fd, int src)
{
	if (redir != -2)
		dup2(redir, src);
	else if (fd != src)
		dup2(fd, src);
}

void	msh_router(t_shell *sh, t_cmd *cmd)
{
	void	*builtin;
	char	*pathname;

	builtin  = msh_isbuiltin(*cmd->args);
	if (builtin)
		;
	else
	{
		pathname = msh_getpathname(*cmd->args, sh->envp);
		fprintf (stderr, "\n\npatname: [%s]\n\n" ,pathname);
		for (int i = 0; *(cmd->args + i); i ++)
			fprintf (stderr, "\n\n[%s]%s" ,*(cmd->args), *(cmd->args + i + 1) ? " " : "\n\n");
		execve(pathname, cmd->args, sh->envp);
	}
	close (cmd->fdout.ffd);
	close (cmd->fdin.ffd);
	msh_cleanshell(sh);
}

void	msh_waitpids(t_list **lst)
{
	t_list	*current_pid;
	int		c_status;
	int		port;

	c_status = 0;
	current_pid = *lst;
	while (current_pid)
	{
		port = *(int *)current_pid->content;
		waitpid(port, &c_status, 0);
		current_pid = current_pid->next;
		if (WIFEXITED(c_status))
			g_rstatus = WEXITSTATUS(c_status);
		if (WIFSIGNALED(c_status))
			g_rstatus = 128 + WTERMSIG(c_status);
	}
}
