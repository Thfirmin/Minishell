/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expnd_dquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:59 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 17:13:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_dquote_syntax(char *str);

char	*msh_expnd_dquote(char **line, char **argv, char **envp)
{
	char	*str;
	char	*tmp;

	*line += 1;
	str = 0;
	if (!msh_dquote_syntax(*line))
		return (0);
	while (*(*line) && (*(*line) != '\"'))
	{
		if (*(*line) == '$')
			tmp = msh_expnd_env(line, argv, envp);
		else
			tmp = msh_expnd_txt(line, "$\"");
		str = msh_unify(str, tmp);
	}
	if (*(*line))
		*line += 1;
	if (!str || !*str)
	{
		free (str);
		str = ft_strdup(" ");
	}
	return (str);
}

static int	msh_dquote_syntax(char *str)
{
	while (*str && (*str != '\"'))
		str ++;
	if (!*str)
	{
		msh_perror(0, "expansion", "unterminated double quote");
		return (0);
	}
	return (1);
}
