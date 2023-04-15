/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:10:27 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 16:12:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*msh_cmdnew(char **arg, int fdin, int fdout)
{
	t_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (cmd)
	{
		cmd->arg = arg;
		cmd->fdin = fdin;
		cmd->fdout = fdout;
	}
	else
		errno = ENOMEM;
	return (cmd);
}
