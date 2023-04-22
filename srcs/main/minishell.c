/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:34:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/21 23:43:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*node;
	char	*str;

	if (argc != 2)
		return (2);
	(void) envp;
	str = malloc (ft_strlen(argv[1]) + 1);
	ft_strlcpy(str, argv[1], ft_strlen(argv[1]) + 1);
	ft_printf ("line = %s\n", str);
	node = msh_parser(str);
	if (!node)
		msh_perror(0, "parser", 0);
	msh_print(node);
	msh_cmdclean(&node);
	free (str);
	return (0);
}

void	msh_print(t_cmd *cmd)
{
	int	i;
	int	aux;

	i = 0;
	while (cmd)
	{
		aux = -1;
		printf ("\n");
		printf ("cmd[%d]: %p\n", i, cmd);
		printf ("\tfdin: [%s](%d)\n", cmd->fdin.fnm, cmd->fdin.ffd);
		printf ("\tfdout: [%s](%d)\n", cmd->fdout.fnm, cmd->fdout.ffd);
		if (cmd->args)
		{
			printf ("\t");
			while (*(cmd->args + ++aux))
				printf ("[%s] ", *(cmd->args + aux));
			printf ("\n");
		}
		cmd = cmd->next;
		i ++;
	}
}
