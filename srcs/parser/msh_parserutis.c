/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parserutis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:47:33 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 11:17:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_redout(char *str, t_fd *in, t_fd *out, int oper);

void	msh_redin(char *str, t_fd *in, t_fd *out, int oper);

// Found redirects, identify the method and delegate to correctly function
void	msh_setredir(char *str, t_fd *in, t_fd *out)
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
			while (*str && ft_isspace(*str))
				str++;
			if (opt == '<')
				msh_redin(str, in, out, i);
			else if (opt == '>')
				msh_redout(str, in, out, i);
		}
		else if (*str)
			str ++;
	}
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
void	msh_redin(char *str, t_fd *in, t_fd *out, int oper)
{
	int		fd;
	char	*file;

	if ((oper != 2) && ((in->ffd == -1) || (out->ffd == -1)))
		return ;
	if ((in->ffd != -1) && (in->ffd != -2))
	{
		close (in->ffd);
		in->ffd = -2;
		free (in->fnm);
		in->fnm = 0;
	}
	file = msh_setfile(str);
	if (oper == 1)
		fd = open(file, O_RDONLY, 00644);
	else if (oper == 2)
		fd = msh_heredoc(file);
	if (in->ffd != -1)
		in->fnm = file;
	else
		free (file);
	if (in->ffd != -1)
		in->ffd = fd;
	else
		close (fd);
}

// create setter of fd struct: clean struct, copy file, open'n'fill input
void	msh_redout(char *str, t_fd *in, t_fd *out, int oper)
{
	if ((in->ffd == -1) || (out->ffd == -1))
		return ;
	if ((out->ffd != -1) && (out->ffd != -2))
	{
		close (out->ffd);
		out->ffd = -2;
		free (out->fnm);
		out->fnm = 0;
	}
	out->fnm = msh_setfile(str);
	if (oper == 1)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (oper == 2)
		out->ffd = open(out->fnm, O_WRONLY | O_CREAT | O_APPEND, 00644);
}
