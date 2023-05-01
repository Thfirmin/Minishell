/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:01:07 by llima             #+#    #+#             */
/*   Updated: 2023/04/28 20:40:53 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	msh_check_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_isalpha(arg[i]) || arg[i] == '_')
	{
		while (ft_isalnum(arg[++i]) || arg[i] == '_')
			;
		if (arg[i] == '\0')
			return (0);
	}
	ft_printf("unset: `%s': not a valid identifier\n", arg);
	g_rstatus = 1;
	return (1);
}

void	msh_unset(char **args, t_env *env)
{
	int	i;
	int	index;

	i = 0;
	g_rstatus = 0;
	while (args[++i])
	{
		index = msh_arr_srch(env->var_list, args[i]);
		if (!msh_check_arg(args[i]) && index != -1)
		{
			free(env->var_list[index]);
			while (env->var_list[++index])
				env->var_list[index - 1] = env->var_list[index];
			env->var_list[index - 1] = NULL;
		}
	}
}
