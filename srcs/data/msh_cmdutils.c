/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 00:28:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:32:52 by thfirmin         ###   ########.fr       */
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
	return (msh_check_alloc(arg, "cmdnew"));
}

void	msh_cmdclean(t_cmd **cmd)
{
	t_cmd	*nxt;

	if (!cmd)
		return ;
	while (*cmd)
	{
		nxt = *cmd;
		*cmd = (**cmd).next;
		msh_fdclean(&nxt->fdin);
		msh_fdclean(&nxt->fdout);
		nxt->args = msh_splitclean(nxt->args);
		free (nxt);
	}
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
