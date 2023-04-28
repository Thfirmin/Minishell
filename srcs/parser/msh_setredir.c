/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_setredir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:47:33 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 00:21:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*msh_setfile(char *str, t_shell *sh);

static int	msh_redout(char *str, t_fd *io, int oper, t_shell *sh);

static int	msh_redin(char *str, t_fd *io, int oper, t_shell *sh);

// ".....>" sdfsfs
// Found redirects, identify the method and delegate to correctly function
int	msh_setredir(char *str, t_fd *io, t_shell *sh)
{
	int		oper;
	char	opt;

	while (*str)
	{
		oper = 0;
		str += msh_skipquote(str);
		if ((*str == '<') || (*str == '>'))
		{
			opt = *str;
			while (*(str + oper) && (*(str + oper) == opt))
				oper ++;
			str += oper;
			if (opt == '<')
				if (msh_redin(str, io, oper, sh) < 0)
					return (-1);
			if (opt == '>')
				if (msh_redout(str, io, oper, sh) < 0)
					return (-1);
		}
		else if (*str)
			str ++;
	}
	return (0);
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static int	msh_redin(char *str, t_fd *io, int oper, t_shell *sh)
{
	t_fd	aux;

	if ((io[IN].ffd == -1) || (io[OUT].ffd == -1))
	{
		if (oper == 2)
		{
			aux.fnm = msh_setfile(str, sh);
			if (!aux.fnm)
				return (-1);
			aux.ffd = msh_heredoc(aux.fnm);
			msh_fdclean(&aux);
		}
		return (0);
	}
	msh_fdclean(&io[IN]);
	io[IN].fnm = msh_setfile(str, sh);
	if (!io[IN].fnm)
		return (-1);
	if (oper == 1)
		io[IN].ffd = open(io[IN].fnm, O_RDONLY, 00644);
	else if (oper == 2)
		io[IN].ffd = msh_heredoc(io[IN].fnm);
	return (0);
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
static int	msh_redout(char *str, t_fd *io, int oper, t_shell *sh)
{
	if ((io[IN].ffd == -1) || (io[OUT].ffd == -1))
		return (0);
	msh_fdclean(&io[OUT]);
	io[OUT].fnm = msh_setfile(str, sh);
	if (!io[OUT].fnm)
		return (-1);
	if (oper == 1)
		io[OUT].ffd = open(io[OUT].fnm, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (oper == 2)
		io[OUT].ffd = open(io[OUT].fnm, O_WRONLY | O_CREAT | O_APPEND, 00644);
	return (0);
}

static char	*msh_setfile(char *str, t_shell *sh)
{
	char	*tmp;
	char	*file;
	int		i;
	char	opt;

	i = 0;
	while (ft_isspace(*str))
		str ++;
	if ((*(str + i) == '\'') || (*(str + i) == '\"'))
	{
		opt = *(str + i++);
		while (*(str + i) != opt)
			i ++;
		i++;
	}
	else
		while (*(str + i) && !ft_strchr("<>| \t\n\v\r\f", *(str + i)))
			i ++;
	tmp = ft_substr(str, 0, i);
	file = msh_expansion(tmp, sh->argv, sh->envp);
	free (tmp);
	return (msh_check_alloc(file, "setfile"));
}
