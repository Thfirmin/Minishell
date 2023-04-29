/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:50:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 14:06:52 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Execute function
 *	* If is builtin: in one, just call it, in two or more, put in process
 *	* If is command: put in process
 */
int	msh_confirmio(t_cmd *cmd);

void	msh_executor(t_shell *sh)
{
	char	*pathname;

	if (!sh->cmd)
		return ;
	execute_builtins(sh->cmd->args, sh->env, sh);
	pathname = msh_getpathname(*sh->cmd->args, sh->env->var_list);
	execve(pathname, sh->cmd->args, sh->env->var_list);

	/*t_cmd	*cmd;
	t_list	*node;
	void	*builtin;
	int		prevpipe;

	if (!sh->cmd)
		return ;
	node = 0;
	cmd = sh->cmd;
	builtin = msh_isbuiltin(*sh->cmd->args);
	prevpipe = dup(0);
	if ((!cmd->next) && (builtin)) // builtin e Commando único 
		;
	else // builtin e commandos com pipe
	{
		while (cmd)
		{
			if (msh_confirmio(cmd))
			{
				if (cmd->next)
					msh_fodase1(sh, cmd, &prevpipe, &node); // primeiro e meio 
				else
					msh_fodase2(sh, cmd, prevpipe, &node); // ultimo
			}
			cmd = cmd->next;
		}
	}*/
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

void	*msh_isbuiltin(char *cmd)
{
	(void) cmd;
	return (0);
}
