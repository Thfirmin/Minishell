/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:18:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/24 14:48:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*msh_setps1(char **envp);

t_cmd	*msh_prompt(char **envp)
{
	char		*ps1;
	char		*prompt;
	t_cmd		*cmd;

	cmd = 0;
	ps1 = msh_setps1(envp);
	if (!ps1)
		return (0);
	prompt = readline(ps1);
	if (!prompt)
		exit (0);
	if (msh_lexer(prompt))
		cmd = msh_parser(prompt);
	free (prompt);
	free (ps1);
	return (cmd);
}

static char	*msh_setps1(char **envp)
{
	char	*ps1;

	(void) envp;
	ps1 = ft_strdup("minishell$> ");
	if (!ps1)
	{
		errno = ENOMEM;
		msh_perror(0, "ps1", 0);
	}
	return (ps1);
}
