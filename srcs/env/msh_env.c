/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:18:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/11 01:46:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_initvar(t_env **env);

static t_env	*msh_newvar(char *var);

// Copy env variables and init new useful variables to turn on minishell
t_env	*msh_initenv(char *envp[])
{
	int		i;
	t_env	*env;
	t_env	*var;

	i = -1;
	env = 0;
	while (*(envp + ++i))
	{
		// copy variables
		var = msh_newvar(*(envp + i));
		if (!var)
		{
			msh_envclear(&env);
			return (0);
		}
		msh_envadd_back(&env, var);
	}
	if (msh_initvar(&env))
		msh_envclear(&env);
	return (env);
}

// cut variable string and create an env node
static t_env	*msh_newvar(char *var)
{
	t_env	*nenv;
	char	*vlue;
	int		len;

	vlue = ft_strchr(var, '=');
	if (!vlue)
		return (0);
	len = (int)(vlue - var);
	nenv = msh_envnew(ft_substr(var, 0, len), ft_strdup(vlue + 1));
	return (nenv);
}

// Initialize useful variables out of original env
static int	msh_initvar(t_env **env)
{
	t_env		*var;
	int			i;
	const char	*key[] = {
		"PS1=\e[32mMinishell$> \e[m",
		0
	};

	i = -1;
	while (*(key + ++i))
	{
		var = msh_newvar((char *)*(key + i));
		if (!var)
			return (1);
		msh_envadd_back(env, var);
	}
	return (0);
}
