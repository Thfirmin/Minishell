/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:18:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/27 23:32:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*msh_setps1(char **envp);

/*
 * > Read line
 * > Orchestra line: send to lexer and parser
 * > Process line: manipulate to inline and multiline prompt
 * > Add history
 * > Return command table
 */
void	msh_prompt(t_shell *sh)
{
	char		*ps1;
	char		*prompt;

	ps1 = msh_setps1(sh->envp);
	if (!ps1)
		return ;
	prompt = cs_get_line(ps1);
	free (ps1);
	if (!prompt)
		exit (0);
	if (msh_lexer(prompt))
		msh_parser(prompt, sh);
	free (prompt);
}

// Take prompt line
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
