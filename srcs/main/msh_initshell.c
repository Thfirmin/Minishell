/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_initshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:20:05 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/26 20:24:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	msh_initshell(char **argv, char **envp)
{
	t_shell	sh;

	ft_memset(&sh, 0, sizeof(t_shell));
	sh.argv = argv;
	sh.envp = envp;
	return (sh);
}
