/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:03:27 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/15 16:42:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Splitar os pipes
// Passar o rodo no redirect
static void	print_args(char **args);

static char	**msh_pipe_split(char *line);

t_cmd	*msh_parser(char *line)
{
	t_cmd	*cmd;
	char	**args;

	cmd = msh_cmdnew(0, -1, -1);
	args = msh_pipe_split(line);
	(void) line;
	print_args(args);
	return (cmd);
}

static char	**msh_pipe_split(char *line)
{
	(void) line;
	return (0);
}

static void	print_args(char **args)
{
	int i;

	ft_printf("-------------------------\n");
	ft_printf ("\nargs: %p\n", args);
	i = -1;
	if (args)
		while (*(args + ++i))
			ft_printf ("\"%s\" ", *(args + i));
	ft_printf ("\n");
	ft_printf("-------------------------\n");
}
