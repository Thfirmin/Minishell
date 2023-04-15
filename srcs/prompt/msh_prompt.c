/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:21:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 16:52:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*msh_ps1mount(void);

// Take User input
// Verify if is valid
// Desassamble input and assemble a command table with it

t_cmd	*msh_prompt(void)
{
	char	*ps1;
	char	*line;
	t_cmd	*cmd;

	cmd = 0;
	ps1 = msh_ps1mount();
	line = readline(ps1);
	if (msh_lexer(line))
		cmd = msh_parser(line);
	free(ps1);
	free(line);
	return (cmd);
}

static char	*msh_ps1mount(void)
{
	char	*ps1;

	ps1 = ft_strdup("\e[31mMinihell$>\e[m");
	return (ps1);
}
