/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:35:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 12:46:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_expansion(char *line, char **argv, char **envp)
{
	char	*str;
	char	*tmp;

	if (!line)
		return (0);
	str = 0;
	while (*line)
	{
		if (*line == '$')
			tmp = msh_expnd_env(&line, argv, envp);
		else if (*line == '\"')
			tmp = msh_expnd_dquote(&line, argv, envp);
		else if (*line == '\'')
			tmp = msh_expnd_squote(&line);
		else
			tmp = msh_expnd_txt(&line, "$\'\"");
		str = msh_unify(str, tmp);
		if (!str)
			return (0);
	}
	if (!str)
		str = msh_check_alloc(ft_calloc(1, 1), "expansion");
	return (str);
}
