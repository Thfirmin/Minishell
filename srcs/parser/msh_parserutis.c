/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parserutis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:47:33 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 21:47:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_redout(char *str, t_fd *in, t_fd *out, int oper);

static int	msh_redin(char *str, t_fd *in, t_fd *out, int oper);

// Found redirects, identify the method and delegate to correctly function
int	msh_setredir(char *str, t_fd *in, t_fd *out)
{
	char	opt;
	int		i;

	while (*str)
	{
		i = 0;
		opt = 0;
		str += msh_skipquote(str);
		if ((*str == '<') || (*str == '>'))
		{
			opt = *str;
			while ((*str + i) && (*(str + i) == opt))
				i ++;
			str += i;
			if (opt == '<')
				if (msh_redin(str, in, out, i) < 0)
					return (-1);
			if (opt == '>')
				if (msh_redout(str, in, out, i) < 0)
					return (-1);
		}
		else if (*str)
			str ++;
	}
	return (0);
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static int	msh_redin(char *str, t_fd *in, t_fd *out, int oper)
{
	t_fd	aux;

	if ((in->ffd == -1) || (out->ffd == -1))
	{
		if (oper == 2)
		{
			aux.fnm = msh_setfile(str);
			if (!aux.fnm)
				return (-1);
			aux.ffd = msh_heredoc(aux.fnm);
			msh_fdclean(&aux);
		}
		return (0);
	}
	msh_fdclean(in);
	in->fnm = msh_setfile(str);
	if (!in->fnm)
		return (-1);
	if (oper == 1)
		in->ffd = open(in->fnm, O_RDONLY, 00644);
	else if (oper == 2)
		in->ffd = msh_heredoc(in->fnm);
	return (0);
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static int	msh_redout(char *str, t_fd *in, t_fd *out, int oper)
{
	if ((in->ffd == -1) || (out->ffd == -1))
		return (0);
	msh_fdclean(out);
	out->fnm = msh_setfile(str);
	if (!out->fnm)
		return (-1);
	if (oper == 1)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (oper == 2)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_APPEND, 00644);
	return (0);
}
