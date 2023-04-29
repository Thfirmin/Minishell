/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_mountarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:51:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:42:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**msh_prompt_args(char *line, t_shell *sh);

static void		msh_clean_redir(char *str);

static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out, char **split);

// Mount a command_table node with redirect and arguments
t_cmd	*msh_mountarg(char *line, t_shell *sh)
{
	t_cmd	*cmd;
	t_fd	io[2];
	char	**args;

	io[IN].fnm = 0;
	io[IN].ffd = -2;
	io[OUT].fnm = 0;
	io[OUT].ffd = -2;
	args = 0;
	if (msh_setredir(line, io, sh) < 0)
		return (msh_mountarg_error(&io[IN], &io[OUT], args));
	msh_clean_redir(line);
	args = msh_prompt_args(line, sh);
	if (!args)
		return (msh_mountarg_error(&io[IN], &io[OUT], args));
	cmd = msh_cmdnew(&io[IN], &io[OUT], args);
	if (!cmd)
		cmd = msh_mountarg_error(&io[IN], &io[OUT], args);
	return (cmd);
}

// Demanded error steps before returning
static t_cmd	*msh_mountarg_error(t_fd *in, t_fd *out, char **split)
{
	split = msh_splitclean(split);
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

static char	**msh_prompt_args(char *line, t_shell *sh)
{
	char	**args;
	char	*expnd;
	int		i;
	int		j;

	args = msh_prompt_split(line, " \t\n\v\f\r");
	if (!args)
		return (0);
	i = 0;
	while (*(args + i))
	{
		expnd = msh_expansion(*(args + i), sh->argv, sh->envp);
		free (*(args + i));
		if (!expnd)
		{
			j = (i - 1);
			while (*(args + ++j))
				*(args + j) = *(args + (j + 1));
			continue ;
		}
		*(args + i) = expnd;
		i ++;
	}
	return (args);
}
