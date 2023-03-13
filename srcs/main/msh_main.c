/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:53:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/03/11 18:54:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_printenv(t_env *env);

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*prompt;
	t_env	*env;
	
	env = msh_initenv(envp); // put in initshell
	// Needed steps before begin definitly minishell
	msh_initshell();
	// Take prompt checking lexical line add history and control terminal I/O
	prompt = msh_prompt();
	// Read/analysis prompt and execute commands (under to changing)
	ft_lstiter(prompt, 0);
	// Clean prompt
	ft_lstclear(&prompt);
	(void) argc;
	(void) argv;
	msh_printenv(env);
	msh_envclear(&env); // Put in clearshell
	// Do all needed steps before exit the shell
	msh_clearshell();
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
