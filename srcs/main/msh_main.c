/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:53:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/11 01:49:59 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_printenv(t_env *env);

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*env;
	
	(void) argc;
	(void) argv;
	env = msh_initenv(envp);
	msh_printenv(env);
	msh_envclear(&env);
	return (0);
}

static void	msh_printenv(t_env *env)
{
	while (env)
	{
		ft_printf ("%s=%s\n", env->key, env->vlue);
		env = env->next;
	}
}
