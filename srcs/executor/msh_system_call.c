/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_system_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:30:04 by thfirmin          #+#    #+#             */
/*   Updated: 2023/04/28 16:18:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	msh_system_call(t_cmd *cmd, t_shell *sh)
{
	char	*pathname;

	pathname = msh_getpathname(*cmd->args, sh->envp);
	printf ("pathname: [%s]\n", pathname);
	free (pathname);
}
