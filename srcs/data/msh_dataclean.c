/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cmdclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:48 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:39:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		msh_splitclean(&nxt->args);
		free (nxt);
	}
}

void	msh_splitclean(char ***split)
{
	int		i;
	char	**aux;

	i = -1;
	if (!*split)
		return ;
	aux = *split;
	while (*(aux + ++i))
		free (*(aux + i));
	free (aux);
	*split = 0;
}

void	msh_fdclean(t_fd *fd)
{
	if (!fd)
		return ;
	if ((fd->ffd != -1) && (fd->ffd != -2))
	{
		close(fd->ffd);
		fd->ffd = -2;
	}
	if (fd->fnm)
	{
		free (fd->fnm);
		fd->fnm = 0;
	}
}
