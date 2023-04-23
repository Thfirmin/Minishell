/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/23 12:38:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Parser algorithm

t_cmd	*msh_parser(char *line)
{
	char	**args;
	int		aux;
	t_cmd	*cmd;
	t_cmd	*node;

	if (!line || !*line)
		return (0);
	args = msh_prompt_split(line, '|');
	if (!args)
		return (0);
	cmd = 0;
	aux = -1;
	while (*(args + ++aux))
	{
		node = msh_mountarg(*(args + aux));
		if (!node)
		{
			msh_cmdclean(&cmd);
			msh_splitclean(&args);
			return (0);
		}
		msh_cmdadd_back(&cmd, node);
	}
	msh_splitclean(&args);
	return (cmd);
}
