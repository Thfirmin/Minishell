/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:39:43 by llima             #+#    #+#             */
/*   Updated: 2023/04/28 15:25:35 by llima            ###   ########.fr       */
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

//[]Get PWD from env (Not getcwd)
// It doesn't. It updates with cd but it's saved somewhere else.
//[X]Should not take arguments
//	They don't seem to make a difference, anyway
//[X]What if the variable is unset?
//	Doesn't interfere with anything
//[]What if there isn't a path to PWD?
//When you export a PWD, it changes to that directory, even if it doesn't exist(?)
//But then pwd shows you the last directory you were in
//Maybe it gets the path that cd tries to access?
