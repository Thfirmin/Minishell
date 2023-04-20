/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:34:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/20 10:58:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_print(t_cmd *cmd);

char	*line = "<<sqn cat | grep \"> ola\" | wc -l | echo $1 mundo >> mundo > mundao";

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*node;
	char	*str;
	(void) argc;
	(void) argv;
	(void) envp;

	str = malloc (ft_strlen(line) + 1);
	ft_strlcpy(str, line, ft_strlen(line) + 1);
	ft_printf ("line = %s\n");
	node = msh_parser(str);
	if (!node)
		msh_perror("parser", 0);
	msh_print(node);
	msh_cmdclean(&node);
	free (str);
	return (0);
}

static void	msh_print(t_cmd *cmd)
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
