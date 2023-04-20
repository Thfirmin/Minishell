/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:58:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*msh_parser(char *line)
{
	char	**args;
	int		aux;
	t_cmd	*cmd;
	t_cmd	*node;

	// Split by pipe
	args = msh_pipe_split(line);
	if (!args)
		return (0);
	cmd = 0;
	// mount arg
	aux = -1;
	while (*(args + ++aux))
	{
		node = msh_mountarg(*(args + aux));
		if (!node)
		{
			msh_cmdclean(&cmd);
			return (0);
		}
		msh_cmdadd_back(&cmd, node);
	}
	// add to cmd tabble
	return (cmd);
}
