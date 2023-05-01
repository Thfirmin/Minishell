/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:39:43 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 20:02:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_pwd(char **args, t_env *env)
{
	(void) args;
	g_rstatus = 0;
	if (env->pwd)
		ft_printf("%s\n", env->pwd);
	else
	{
		free(env->pwd);
		env->pwd = getcwd(NULL, 0);
		ft_printf("%s\n", env->pwd);
	}
}
