/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/19 10:58:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*msh_parsererror(char *head);

t_cmd	*msh_parser(char *line)
{
	//char	**args;

	// Split by pipe
	/*
	args = msh_pipe_split(line);
	if (!args)
		return (msh_parsererror("-bash:parser"));
	*/
	// mount arg
	if (!line)
		msh_parsererror(0);

	// add to cmd tabble
	return (msh_mountarg(line));
}

static t_cmd	*msh_parsererror(char *head)
{
	perror(head);
	return (0);
}
