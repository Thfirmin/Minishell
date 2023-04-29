/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_initshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:20:05 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 20:11:40 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	msh_initshell(char **argv, char **envp)
{
	t_shell	sh;

	ft_memset(&sh, 0, sizeof(t_shell));
	sh.argv = argv;
	sh.envp = envp;
	sh.io[IN] = dup(STDIN_FILENO);
	sh.io[OUT] = dup(STDOUT_FILENO);
	return (sh);
}

void	msh_cleanshell(t_shell *sh)
{
	close(sh->io[IN]);
	close(sh->io[OUT]);
	msh_cmdclean(&sh->cmd);
}
