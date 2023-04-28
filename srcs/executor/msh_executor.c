/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:50:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 14:31:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Execute function
 *	* If is builtin: in one, just call it, in two or more, put in process
 *	* If is command: put in process
 */
void	msh_exec_step(t_cmd *cmd, short bin);

void	msh_executor(t_shell *sh)
{
	t_cmd	*cmd;
	int		size;
	short	step;

	cmd = sh->cmd;
	size = msh_cmdsize(cmd);
	step = 0;
	while (cmd)
	{
		if (!bin && !cmd->next)
			msh
		msh_exec_step(cmd, step);
		cmd = cmd->next;
		step = 1;
	}
}

void	msh_exec_step(t_cmd *cmd, short bin)
{
	if (!bin)
	{
		if (!cmd->next)
			printf ("[%s] i'm the unique command", *cmd->args);
		else
			printf ("[%s] i'm the first command\n", *cmd->args);
	}
	else if (!cmd->next)
		printf ("[%s] i'm the last command\n", *cmd->args);
	else
		printf ("[%s] i'm the middle command\n", *cmd->args);
}
