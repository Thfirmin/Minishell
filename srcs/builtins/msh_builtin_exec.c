/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:28:13 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 13:46:13 by llima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtins(char **args, t_env *env, t_shell *sh)
{
	if (ft_strncmp(args[0], "echo", 5) == 0)
		msh_echo(args);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		msh_cd(args, env);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		msh_pwd(args, env);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		msh_export(args, env);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		msh_unset(args, env);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		msh_env(args, env);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		msh_exit(args, env, sh);
}
