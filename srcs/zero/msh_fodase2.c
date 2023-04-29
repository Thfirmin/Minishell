/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_fodase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:42:46 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 22:01:12 by tde-souz         ###   ########.fr       */
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
	if (cpid == 0)
	{
		msh_resetsignal();
		msh_dupfds(cmd->fdout.ffd, STDOUT_FILENO, STDOUT_FILENO);
		msh_dupfds(cmd->fdin.ffd, prevpipe, STDIN_FILENO);
		close (prevpipe);
		msh_router(sh, cmd);
	}
	else
	{
		ft_lstadd_back(lst, ft_lstnew(0, cpid));
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
		execve(pathname, cmd->args, sh->envp);
	}
	close (cmd->fdout.ffd);
	close (cmd->fdin.ffd);
	msh_cleanshell(sh);
}

void	ft_free_lst(t_list *lst)
{
	// adicionado postumamente
	t_list	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	lst = 0;
}

void	msh_waitpids(t_list **lst)
{
	t_list	*current_pid;
	int		c_status;

	c_status = 0;
	current_pid = *lst;
	while (current_pid)
	{
		waitpid(current_pid->value, &c_status, 0);
		current_pid = current_pid->next;
		if (WIFEXITED(c_status))
			g_rstatus = WEXITSTATUS(c_status);
		if (WIFSIGNALED(c_status))
			g_rstatus = 128 + WTERMSIG(c_status);
	}
	ft_free_lst(*lst);
}
