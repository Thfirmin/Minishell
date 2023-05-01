/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima <llima@student.42.rio>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:28:13 by llima             #+#    #+#             */
/*   Updated: 2023/04/29 16:38:07 by thfirmin         ###   ########.fr       */
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

void	msh_builtin_exec(t_shell *sh, t_cmd *cmd)
{
	if (!msh_confirmio(cmd))
		return ;
	msh_setfd(STDIN_FILENO, &cmd->fdin, STDIN_FILENO);
	msh_setfd(STDOUT_FILENO, &cmd->fdout, STDOUT_FILENO);
	execute_builtins(cmd->args, sh->env, sh);
	dup2(sh->io[IN], STDIN_FILENO);
	dup2(sh->io[OUT], STDOUT_FILENO);
}

int	msh_isbuiltin(char *cmd)
{
	int			i;
	const char	*bltn[] = {
		"echo",
		"cd",
		"pwd",
		"export",
		"unset",
		"env",
		"exit",
		0
	};

	i = -1;
	while (*(bltn + ++i))
		if (!ft_strncmp(*(bltn + i), cmd, ft_strlen(*(bltn + i))))
			return (1);
	return (0);
}
