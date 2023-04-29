/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_getpathname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 16:33:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_getrelative(char *cmd, char *env);

char	*msh_getpathname(char *cmd, char **envp)
{
	char	*pathname;
	char	*path;

	if (!cmd || !envp)
		return (0);
	pathname = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK))
			g_rstatus = msh_perror(127, cmd, 0);
		else
			pathname = ft_strdup(cmd);
	}
	else
	{
		path = msh_getenv_value("PATH", envp);
		if (!path)
			return (0);
		pathname = msh_getrelative(cmd, path);
		free (path);
	}
	return (pathname);
}

char	*msh_getrelative(char *cmd, char *env)
{
	char	**path;
	char	*aux;
	int		i;

	path = ft_split(env, ':');
	if (!path)
		return (0);
	i = -1;
	while (*(path + ++i))
	{
		aux = ft_strjoin(*(path + i), "/");
		free (*(path + i));
		*(path + i) = aux;
		aux = ft_strjoin(*(path + i), cmd);
		if (!access(aux, F_OK | X_OK))
			break ;
		free (aux);
		aux = 0;
	}
	msh_splitclean(&path);
	if (!aux)
		g_rstatus = msh_perror(127, cmd, "command not found");
	return (aux);
}
