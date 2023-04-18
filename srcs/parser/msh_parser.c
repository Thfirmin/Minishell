/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:04:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/18 08:22:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*msh_parsererror(char *head);

t_cmd	*msh_parser(char *line)
{
	char	**args;

	// Split by pipe
	args = msh_pipe_split(line);
	if (!args)
		return (msh_parsererror("-bash:parser"));
	// FIXME: tmp
	printf ("args: %p\n", args);
	if (args)
	{

		for (int i = 0; *(args + i); i ++)
		{
			printf ("[%s] ", *(args + i));
			free (*(args + i));
		}
	}
	printf ("\n");
	free (args); 
	// FIXME: end
	// mount arg
	// add to cmd tabble
	return (0);
}

static t_cmd	*msh_parsererror(char *head)
{
	perror(head);
	return (0);
}
