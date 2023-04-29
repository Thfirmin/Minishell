/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 03:34:40 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 12:32:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_rstatus = 0;

char	*tf_readline(char *prompt);

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	sh;

	sh = msh_initshell(argv, envp);
	msh_setsignal();
	(void) argc;
	while (1)
	{
		msh_prompt(&sh);
		msh_executor(&sh);
		msh_cmdclean(&sh.cmd);
		/*msh_executor(&sh);
		msh_cmdclean(&sh.cmd); // << here*/
	}
	msh_shclean(&sh);
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
