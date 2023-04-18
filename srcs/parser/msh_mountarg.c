/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 11:24:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_setredir(char *str, t_fd *in, t_fd *out);

t_cmd	*msh_mountarg(char *line)
{
	t_cmd	*cmd;
	t_fd	fdin;
	t_fd	fdout;

	fdin.fnm = 0;
	fdin.ffd = -2;
	fdout.fnm = 0;
	fdout.ffd = -2;
	msh_redir(line, &fdin, &fdout);
	(void)cmd;
	return (0);
}

static void	msh_setredir(char *str, t_fd *in, t_fd *out)
{
	char	opt;
	int		i;

	if (!str)
		return ;
	while (*str)
	{
		i = 0;
		opt = 0;
		str += msh_skipquote(str);
		if ((*str == '<') || (*str == '>'))
			opt = *str;
		while ((*str + i) && (*(str + i) == opt))
			i ++;
		ft_memset(str, ' ', i);
		str += i;
		if ((opt == '<') && (((in->ffd != -1) && (out->ffd != -1)) || (i == 2)))
			msh_redin(str, fdin, i);
		else if ((opt == '>') && ((in->ffd != -1) && (out->ffd != -1)))
			msh_redout(str, fdout, i);
		if (*str)
			str ++;
	}
}

// create setter of fd struct: clean struct, copy file, open'n'fill input 
