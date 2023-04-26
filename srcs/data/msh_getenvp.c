/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_getenvp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:03:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 11:59:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_getenvp(char *key, char **envp)
{
	int	i;
	int	len;

	if (!key || !envp)
		return (0);
	i = -1;
	len = ft_strlen(key);
	while (*(envp + ++i))
		if (!ft_strncmp(key, *(envp + i), len))
			if (*(*(envp + i) + len) == '=')
				return (*(envp + i));
	return (0);
}

char	*msh_getenv_value(char *key, char **envp)
{
	char	*var;

	var = msh_getenvp(key, envp);
	if (var)
		return (ft_strdup(ft_strchr(var, '=') + 1));
	else
		return (0);
}
