/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_envutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:17:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/10 02:35:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*msh_envnew(char *key, char *vlue)
{
	t_env	*var;

	var = ft_calloc(1, sizeof(t_env));
	if (!var)
	{
		errno = ENOMEM;
		return (var);
	}
	(*var).key = key;
	(*var).vlue = vlue;
	(*var).next = 0;
	return (var);
}

void	msh_envadd_back(t_env **env, t_env *var)
{
	t_env	*aux;

	aux = *env;
	if (aux)
		while (aux->next)
			aux = aux->next;
	if (!aux)
		*env = var;
	else
		aux->next = var;
}

void	msh_envclear(t_env **env)
{
	t_env	*nxt;

	while (*env)
	{
		nxt = (**env).next;
		free (*env);
		*env = nxt;
	}
}
