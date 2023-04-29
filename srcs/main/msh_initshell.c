/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_initshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:20:05 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/29 00:22:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	msh_initshell(char **argv, char **envp)
{
	t_shell	sh;

	ft_memset(&sh, 0, sizeof(t_shell));
	sh.argv = argv;
	sh.envp = envp; // trocar pela copia do coelho
	sh.io[IN] = dup(STDIN_FILENO);
	sh.io[OUT] = dup(STDOUT_FILENO);
	return (sh);
}
