/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:50:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 20:51:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Execute function
 *	* If is builtin: in one, just call it, in two or more, put in process
 *	* If is command: put in process
 */
static int	msh_confirmio(t_cmd *cmd);

void	msh_executor(t_shell *sh)
{
	t_cmd	*cmd;
	t_list	*node;
	void	*builtin;
	int		prevpipe;

	node = 0;
	cmd = sh->cmd;
	builtin = msh_isbuiltin(*sh->cmd->args);
	prevpipe = dup(0);
	if ((!cmd->next) && (builtin)) /* builtin e Commando único */
		;
	else // builtin e commandos com pipe
	{
		while (cmd)
		{
			if (msh_confirmio(cmd))
			{
				if (cmd->next)
					msh_fodase1(sh, cmd, &prevpipe, &node); /* primeiro e meio */
				else
					msh_fodase2(sh, cmd, prevpipe, &node); /* ultimo */
			}
			cmd = cmd->next;
		}
	}
}

static int	msh_confirmio(t_cmd *cmd)
{
	(void) cmd;
	return (1);
}

void	*msh_isbuiltin(char *cmd)
{
	(void) cmd;
	return (0);
}
