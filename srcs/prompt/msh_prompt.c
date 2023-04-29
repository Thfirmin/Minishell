/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:18:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 09:31:10 by thfirmin         ###   ########.fr       */
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
	char		*ptr;

	ps1 = msh_setps1(sh->envp);
	if (!ps1)
		return ;
	prompt = readline(ps1);
	free (ps1);
	if (!prompt)
		exit (0); // exit
	if (msh_lexer(prompt))
		msh_parser(prompt, sh);
	ptr = prompt;
	if (ptr)
		while (ft_isspace(*ptr))
			ptr ++;
	if (ptr && *ptr)
		add_history(prompt);
	free (prompt);
}

// Take prompt line
static char	*msh_setps1(char **envp)
{
	char	*ps1;

	(void) envp;
	ps1 = ft_strdup("minishell$> ");
	return (msh_check_alloc(ps1, "setps1"));
}
