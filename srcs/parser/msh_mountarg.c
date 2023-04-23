/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/23 13:05:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		msh_clean_redir(char *str);

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

// Clean all redirect tokens from prompt
static void	msh_clean_redir(char *str)
{
	int		i;

	while (*str)
	{
		i = 0;
		str += msh_skipquote(str);
		if ((*str == '<') || (*str == '>'))
		{
			while ((*(str + i) == '<') || (*(str + i) == '>'))
				i ++;
			while (ft_isspace(*(str + i)))
				i ++;
			if ((*(str + i) == '\'') || (*(str + i) == '\"'))
				i += (msh_skipquote((str + i)) + 1);
			else
				while (*(str + i) && !ft_strchr("<>| \t\n\v\r\f", *(str + i)))
					i ++;
			ft_memset(str, ' ', i);
			str += i;
		}
		else if (*str >= 9 && *str <= 13)
			*str++ = ' ';
		else if (*str)
			str ++;
	}
}
