/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 11:25:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out);

t_cmd	*msh_mountarg(char *line)
{
	t_cmd	*cmd;
	t_fd	fdin;
	t_fd	fdout;
	char	**args;

	fdin.fnm = 0;
	fdin.ffd = -2;
	fdout.fnm = 0;
	fdout.ffd = -2;
	msh_setredir(line, &fdin, &fdout);
	msh_clean_redir(line);
	args = ft_split(line, ' ');
	if (!args)
		return (msh_mountarg_error(&fdin, &fdout));
	cmd = msh_cmdnew(&fdin, &fdout, args);
	return (cmd);
}

static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out)
{
	if ((in->ffd != -1) && (in->ffd != -2))
		close (in->ffd);
	if ((out->ffd != -1) && (out->ffd != -1))
		close (out->ffd);
	free (in->fnm);
	free (out->fnm);
	return (0);
}

