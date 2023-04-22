/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:40:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out, char **split);

// Mount a command_table node with redirect and arguments
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
	args = 0;
	if (msh_setredir(line, &fdin, &fdout) < 0)
		return (msh_mountarg_error(&fdin, &fdout, args));
	msh_clean_redir(line);
	args = msh_prompt_split(line, ' ');
	if (!args)
		return (msh_mountarg_error(&fdin, &fdout, args));
	cmd = msh_cmdnew(&fdin, &fdout, args);
	if (!cmd)
		cmd = msh_mountarg_error(&fdin, &fdout, args);
	return (cmd);
}

// Demanded error steps before returning
static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out, char **split)
{
	int	i;

	i = -1;
	msh_splitclean(&split);
	msh_fdclean(in);
	msh_fdclean(out);
	return (0);
}
