/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:18:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/10 02:28:32 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Copy env variables and init new useful variables to turn on minishell
t_env	*msh_initenv(char *envp[])
{
	int		i;
	t_env	*env;
	t_env	*var;

	i = -1;
	while (*(envp + ++i))
	{
		// copy variables
		var = msh_envnew(*(envp + i), 0);
		if (!var)
		{
			msh_envclear(&env);
			return (0);
		}
		msh_envadd_back(&env, var);
	}
	return (env);
}
