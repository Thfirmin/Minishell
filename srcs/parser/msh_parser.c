/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 09:57:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Parser algorithm

void	msh_parser(char *line, t_shell *sh)
{
	char	**args;
	int		aux;
	t_cmd	*node;

	if (!line || !*line)
		return ;
	args = msh_prompt_split(line, "|");
	if (!args)
		return ;
	aux = -1;
	while (*(args + ++aux))
	{
		node = msh_mountarg(*(args + aux), sh);
		if (!node)
		{
			msh_cmdclean(&sh->cmd);
			args = msh_splitclean(args);
			return ;
		}
		msh_cmdadd_back(&sh->cmd, node);
	}
	args = msh_splitclean(args);
}
