/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:50:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 20:07:54 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Execute function
 *	* If is builtin: in one, just call it, in two or more, put in process
 *	* If is command: put in process
 */

static void	msh_aux_execve_exec(t_shell *sh, t_cmd *cmd);

static void	msh_aux_builtin_exec(t_shell *sh, t_cmd *cmd);

static void	msh_end_exec(int rdpipe, t_cmd *cmd, t_shell *sh, t_pid **lst);

static void	msh_begin_exec(int *rdpipe, t_cmd *cmd, t_shell *sh, t_pid **lst);

void	msh_executor(t_shell *sh)
{
	t_cmd	*cmd;
	t_pid	*lst;
	int		bltn;
	int		prevpipe;

	if (!sh->cmd)
		return ;
	bltn = msh_isbuiltin(*sh->cmd->args);
	if ((!sh->cmd->next) && (bltn))
		msh_builtin_exec(sh, sh->cmd);
	else
	{
		lst = 0;
		cmd = sh->cmd;
		prevpipe = dup(0);
		while (cmd)
		{
			if (!cmd->next)
				msh_end_exec(prevpipe, cmd, sh, &lst);
			else
				msh_begin_exec(&prevpipe, cmd, sh, &lst);
			cmd = cmd->next;
		}
	}
}

static void	msh_begin_exec(int *rdpipe, t_cmd *cmd, t_shell *sh, t_pid **lst)
{
	int	pid;
	int	nfd[2];

	pipe(nfd);
	if (!msh_confirmio(cmd))
	{
		close (*rdpipe);
		close (nfd[OUT]);
		*rdpipe = nfd[IN];
		return ;
	}
	pid = fork();
	if (!pid)
		msh_so_specific(nfd, rdpipe, cmd, sh);
	else
	{
		msh_pidadd_back(lst, msh_pidnew(pid));
		close (nfd[OUT]);
		close(*rdpipe);
		*rdpipe = nfd[IN];
	}
}

static void	msh_end_exec(int rdpipe, t_cmd *cmd, t_shell *sh, t_pid **lst)
{
	int	builtin;
	int	pid;

	if (!msh_confirmio(cmd))
		return ;
	pid = fork();
	if (!pid)
	{
		msh_resetsignal();
		msh_setfd(sh->io[OUT], &cmd->fdout, STDOUT_FILENO);
		msh_setfd(rdpipe, &cmd->fdin, STDIN_FILENO);
		close (rdpipe);
		builtin = msh_isbuiltin(*cmd->args);
		if (builtin)
			msh_aux_builtin_exec(sh, cmd);
		else
			msh_aux_execve_exec(sh, cmd);
	}
	else
	{
		close (rdpipe);
		msh_pidadd_back(lst, msh_pidnew(pid));
		if (pid > 0)
			msh_waitpid(lst);
	}
}

static void	msh_aux_builtin_exec(t_shell *sh, t_cmd *cmd)
{
	execute_builtins(cmd->args, sh->env, sh);
	msh_shclean(sh);
	exit(0);
}

static void	msh_aux_execve_exec(t_shell *sh, t_cmd *cmd)
{
	char	*pathname;

	pathname = msh_getpathname(*cmd->args, sh->env->var_list);
	if (!pathname)
		exit(127);
	execve(pathname, cmd->args, sh->env->var_list);
}
