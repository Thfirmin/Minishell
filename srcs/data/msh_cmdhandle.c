/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdhandle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:48:04 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/23 12:48:40 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*msh_cmdnew(t_fd *in, t_fd *out, char **args)
{
	t_cmd	*arg;

	arg = ft_calloc(sizeof(t_cmd), 1);
	if (arg)
	{
		arg->fdin.ffd = in->ffd;
		arg->fdin.fnm = in->fnm;
		arg->fdout.ffd = out->ffd;
		arg->fdout.fnm = out->fnm;
		arg->args = args;
		arg->next = 0;
	}
	else
	{
		errno = ENOMEM;
		msh_perror(0, "cmdnew", 0);
	}
	return (arg);
}

void	msh_cmdadd_back(t_cmd **cmd, t_cmd *arg)
{
	t_cmd	*lst;

	if (!*cmd)
		*cmd = arg;
	else
	{
		lst = *cmd;
		while (lst->next)
			lst = lst->next;
		lst->next = arg;
	}
}
