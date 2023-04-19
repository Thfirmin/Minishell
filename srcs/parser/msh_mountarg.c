/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 22:21:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_redout(char *str, t_fd *out, int oper);

static void	msh_redin(char *str, t_fd *in, int oper);

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
	msh_setredir(line, &fdin, &fdout);
	ft_printf("rest: %s\n", line);
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
			msh_redin(str, in, i);
		else if ((opt == '>') && ((in->ffd != -1) && (out->ffd != -1)))
			msh_redout(str, out, i);
		if (*str)
			str ++;
	}
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static void	msh_redin(char *str, t_fd *in, int oper)
{
	int	fdin;

	if ((in->ffd != -2) && (in->ffd != -1))
	{
		close (in->ffd);
		in->ffd = -2;
	}
	while (ft_isspace(*str))
		str ++;
	in->fnm = msh_setfile(str);
	if (!in->fnm)
		return ;
	if (oper == 1)
		fdin = open(in->fnm, O_RDONLY);
	else if (oper == 2)
		fdin = msh_heredoc(in->fnm);
	if (in->ffd != -1)
		in->ffd = fdin;
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static void	msh_redout(char *str, t_fd *out, int oper)
{
	if ((out->ffd != -2) && (out->ffd != -1))
	{
		close (out->ffd);
		out->ffd = -2;
	}
	while (ft_isspace(*str))
		str ++;
	out->fnm = msh_setfile(str);
	if (!out->fnm)
		return ;
	if (oper == 1)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (oper == 2)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_APPEND, 00644);
}
