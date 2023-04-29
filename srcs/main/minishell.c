/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:34:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 20:41:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_rstatus = 0;

char	*tf_readline(char *prompt);

void	msh_print(t_cmd *cmd);

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	sh;

	sh = msh_initshell(argv, envp);
	(void) argc;
	while (1)
	{
		msh_prompt(&sh);
		msh_executor(&sh);
	}
	//msh_print(sh.cmd);
	msh_cleanshell(&sh);
	return (0);
}

char	*tf_readline(char *prompt)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int		blen;

	buff = ft_calloc(sizeof(char), 43);
	if (!buff)
		return (0);
	ft_putstr_fd(prompt, 1);
	line = 0;
	blen = 0;
	while (*(buff + (blen - 1)) != '\n')
	{
		blen = read(0, buff, 42);
		*(buff + blen) = '\0';
		tmp = ft_strjoin(line, buff);
		free (line);
		line = tmp;
	}
	tmp = ft_strtrim(line, "\n");
	free (line);
	free (buff);
	return (tmp);
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
			printf ("[%s]\n", *(cmd->args + aux));
		}
		else
			printf ("\t(%p)\n", cmd->args);
		cmd = cmd->next;
		i ++;
	}
}
