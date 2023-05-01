/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executorutils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:19:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:06:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_setfd(int fd, t_fd *file, int std)
{
	if (file->ffd != -2)
	{
		dup2(file->ffd, std);
		msh_fdclean(file);
	}
	else if (fd != std)
		dup2(fd, std);
}

int	msh_confirmio(t_cmd *cmd)
{
	if (cmd->fdout.ffd == -1)
	{
		access(cmd->fdout.fnm, F_OK | W_OK);
		g_rstatus = msh_perror(1, cmd->fdout.fnm, 0);
		return (0);
	}
	else if (cmd->fdin.ffd == -1)
	{
		access(cmd->fdin.fnm, F_OK | R_OK);
		g_rstatus = msh_perror(1, cmd->fdin.fnm, 0);
		return (0);
	}
	return (1);
}

void	msh_waitpid(t_pid **pid)
{
	t_pid	*current_pid;
	int		c_status;

	c_status = 0;
	current_pid = *pid;
	while (current_pid)
	{
		waitpid(current_pid->pid, &c_status, 0);
		current_pid = current_pid->next;
		if (WIFEXITED(c_status))
			g_rstatus = WEXITSTATUS(c_status);
		if (WIFSIGNALED(c_status))
			g_rstatus = 128 + WTERMSIG(c_status);
	}
	msh_pidclear(pid);
}

void	msh_resetsignal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	msh_so_specific(int nfd[2], int *rdpe, t_cmd *cmd, t_shell *sh)
{
	int	builtin;

	close(nfd[IN]);
	msh_setfd(nfd[OUT], &cmd->fdout, STDOUT_FILENO);
	close(nfd[OUT]);
	msh_setfd(*rdpe, &cmd->fdin, STDIN_FILENO);
	close(*rdpe);
	msh_resetsignal();
	builtin = msh_isbuiltin(*cmd->args);
	if (builtin)
		msh_aux_builtin_exec(sh, cmd);
	else
		msh_aux_execve_exec(sh, cmd);
}
