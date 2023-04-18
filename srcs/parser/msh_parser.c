/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 08:51:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*msh_parsererror(char *head);

t_cmd	*msh_parser(char *line)
{
	//char	**args;
	t_cmd	*node;

	// Split by pipe
	/*
	args = msh_pipe_split(line);
	if (!args)
		return (msh_parsererror("-bash:parser"));
	*/
	// mount arg
	node = msh_mountarg(line);
	// add to cmd tabble
	return (0);
}

static t_cmd	*msh_parsererror(char *head)
{
	perror(head);
	return (0);
}
