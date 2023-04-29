/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:20:34 by llima             #+#    #+#             */
/*   Updated: 2023/04/28 20:41:31 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_env(char **args, t_env *env)
{
	int	i;

	i = 0;
	(void) args;
	while (env->var_list[i])
	{
		ft_printf("%s\n", env->var_list[i]);
		i++;
	}
	g_rstatus = 0;
}
